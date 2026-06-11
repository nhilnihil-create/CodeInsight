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
  cout << endl;
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   " << endl;
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}
 

int main(){
    string S;
    cin >> S;//"123"の場合S[0]=1, S[1]=2, S[2]=3になるので，
    reverse(S.begin(), S.end());//S[2]S[1]S[0]の向きにする
    //つまりS[2]=1, S[1]=2, S[0]=3;になった
    int N = S.size();

    //S[i+2]S[i+1]S[i]=S[i+2]*10^(i+2)+S[i+1]*10^(i+1)+S[i]*10^i
    //なので  その数列がa[i+2]+a[i+1]+a[i]になるようにする
    //vector<ll> a(N);
    //for(int i=0; i<N; i++) a[i] = S[i]*pow(10, i);
    // vector<ll> wa(N+1);
    // wa[0] = 0;
    // for(int i=0; i<N; i++){
    //   wa[i+1] = wa[i]+pow(10, i)*(S[i]-'0');
    // }

    const int MOD = 2019;
    map<int, int> mp;
    ll ans = 0;
    ll wa = 0;//累積和
    ll pow10_i = 1;// pow(10, i)%MOD
    for(int i=0; i<N; i++){
      mp[wa]++;//なぜこの位置なんだ??
      //累積和≡0(mod2019)となるとき，
      //S[i]~S[0]までを並べた数字自体が2019の倍数ということで
      //それは今までのmp[wa]の値に関係なく2019の倍数だから最初にmp[0]++しておくってこと?
      //別の解釈するなら S[i]~S[0]を並べた時の数字が2019の倍数となる，はじめてのiでans++されるように
      //mp[0]++しておくってこと　　かな


      //wa += (S[i] - '0') * pow(10, i);
      wa += (S[i] - '0') * pow10_i;
      wa %= MOD;
      ans += mp[wa];
      //mp[wa]++;
      pow10_i = pow10_i*10 % MOD;
    }

    cout << ans << endl;


}
