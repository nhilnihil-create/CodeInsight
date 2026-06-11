#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}
 
int main(){
	int X, Y, A, B, C;
	cin >> X >> Y >> A >> B >> C;
	vector<ll> p(A), q(B), r(C);
	for(int i=0; i<A; i++) cin >> p[i];	
	for(int i=0; i<B; i++) cin >> q[i];
	for(int i=0; i<C; i++) cin >> r[i];
	sort(p.rbegin(), p.rend());
	sort(q.rbegin(), q.rend());
	sort(r.rbegin(), r.rend());


	//別解　参照 https://atcoder.jp/contests/abc160/submissions/11294466
	//↓ のgreater は昇順　つまりtop()は一番小さい
	priority_queue<ll,vector<ll>,greater<ll>> reds, greens;
	ll red_tasty = 0, green_tasty = 0;
	for(int i=0; i<X; i++){
		red_tasty += p[i];
		reds. push(p[i]);
	}
	for(int i=0; i<Y; i++){
		green_tasty += q[i];
		greens.push(q[i]);
	}
		//ここまでで一旦　AからX個， BからY個とった
	sort(r.begin(), r.end()); //rの最大をO(1)で削除できるように昇順にしとく
	for(int i=0; i<C; i++){
		if(reds.top() < greens.top()){
			if(reds.top() < r.back()){
				red_tasty -= reds.top();
				reds.pop();
				red_tasty += r.back();
				reds.push(r.back()); r.pop_back();
			}
			else break;
		}
		else if(reds.top() >= greens.top()){
			if(greens.top() < r.back()){
				green_tasty -= greens.top();
				greens.pop();
				green_tasty += r.back();
				greens.push(r.back()); r.pop_back();

			}
			else break;
		}
	}

	ll ans = red_tasty + green_tasty;
	cout << ans << endl;


	// //解法みちゃいました．
	// vector<ll> d;
	// for(int i=0; i<X; i++) d.push_back(p[i]);
	// for(int i=0; i<Y; i++) d.push_back(q[i]);
	// for(int i=0; i<C; i++)  d.push_back(r[i]);
	// sort(d.rbegin(), d.rend());
	
	// ll ans = 0;
	// for(int i=0; i<X+Y; i++) ans += d[i];
	// cout << ans << endl;

	

	////////////////////////////////////////////////////
	//以下　累積和とか考えて　最適を探そうとして　ハマってしまった.
	// vector<ll> a_wa(A+1), b_wa(B+1), c_wa(C+1);//累積和
	// a_wa[0] = 0; b_wa[0] = 0; c_wa[0] = 0;
	// for(int i=0; i<A; i++) a_wa[i+1] = a_wa[i] + p[i];
	// for(int i=0; i<B; i++) b_wa[i+1] = b_wa[i] + q[i];
	// for(int i=0; i<C; i++) c_wa[i+1] = c_wa[i] + r[i];
	
	// tasty[i][j]: p,qから合計i個食べる時， 
	//pからj個,qからi-j個食べた時の合計のおいしさ
	// vector<vector<ll>> tasty(X+Y+1, vector<ll>(X, 0));
	// for(int i=0; i<X+Y+1; i++){
	// 	tasty[i][]
	// }

	// ll ans = 0;
	// for(int a_num=0; a_num<=X; a_num++){
	// 	ans = max(ans, a_wa[a_num] + b_wa[X+Y-a_num] + c_wa[])
	// }

	// // tasty[i]: p,qから合計i個食べた時の，おいしさの最大値
	// vector<ll> tasty(X+Y+1, 0);
	// for(int i=0; i=X+Y+1; i++){


	// }
	// for(int c_num=0; c_num<=X+Y; c_num++){

	// }


	// ll ans = 0;
	// // tasty[i]: Aからi個食べて,CからX-i個食べたおいしさ
	// vector<ll> a_tasty(X, 0);
	// for(int a_num=0; a_num<=X; a_num++){
	//     a_tasty[a_num] += a_wa[a_num];// Aからa_num個食べる
	// 	a_tasty[a_num] += c_wa[X-a_num]; //CからX-a_num個食べる
	// }


}
