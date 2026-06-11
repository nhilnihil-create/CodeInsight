#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	int N; cin>>N;
	vector<string> S;

	rep(i,N){
		string s; cin>>s;
		S.push_back(s);
	}
	sort(S.begin(),S.end());

	int num=0;
	string ms=S[0];
	int x=0;
	for(int i=0; i<N; i++){
		if(S[i]==ms){
			x++;
			num = max(x,num);
		}else{
			ms=S[i];
			x=1;
		}
	}

	cerr << num << endl;
	int ct=0; ms=S[0];
	for(int i=0; i<N; i++){
		if(ms==S[i]){
			ct++;
			if(ct==num){
				cout << S[i] << endl;
			}
		}else{
			ms = S[i];
			ct=1;
			if(num==1) cout << S[i] << endl;
		}
	}
	
}