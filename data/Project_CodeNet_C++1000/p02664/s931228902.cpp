#include<bits/stdc++.h>
using namespace std;

using lli=long long int;
	void solve(){
		int N,i,j,p,q;
		string word;
		cin>>word;
		N=word.size();
		for(i=0;i<N;i++){
			if(word[i]=='?')word[i]='D';
		}
		cout<<word;
	}
int main(){
	//cin.tie(0),ios_base::sync_with_stdio(0);
	lli i,t;
	t=1;
	for(i=1;i<=t;i++){
		solve();
	}
}
