#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define dbg_v(v) cout<<#v<<":";for(int i=0;i<(int)v.size();i++) cout<<" "<<v[i]; cout<<endl;
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int t=1;
	//cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int ct=0;
		for(int i=0;i<n-2;i++){
			if(s.substr(i,3)=="ABC")
				ct++;
		}
		cout<<ct<<endl;
	}
}

