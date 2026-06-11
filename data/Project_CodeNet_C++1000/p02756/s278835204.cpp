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
	cin >> S;
	int Q;
	cin >> Q;
	
	int is_reverse = 0;//リバースした回数
	for(int i=0; i<Q; i++){
		int t;
		cin >> t;
		if(t==1){
			//reverse(S.begin(), S.end());
			is_reverse++;
			continue;
		}
		int f; 
		char c;
		cin >> f >> c;
		if((f==1 && is_reverse%2==0)  || (f==2&&is_reverse%2==1)){//コンパイルエラー起きたので()を入れる &&と||を一緒に書くときは注意しなかんのかな?
			S = c + S;
		}
		else{
			S.push_back(c);
		}

	}

	if(is_reverse%2==0){
		cout << S << endl;
		return 0;
	}
	else for(int i=S.size()-1; i>=0; i--) cout << S[i];
	cout << endl;
}
