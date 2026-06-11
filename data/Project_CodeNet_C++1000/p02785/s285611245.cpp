#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll int>
#define vs vector<string>
#define v vector<int>
#define mi map<int,int>
#define mc map<char,int>
//ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
		ll int n,k,i=0;
		cin>>n >>k;
		ll int move=0;
		v A(n);
		for(auto &x:A)cin>>x;
		if(k>=n){move=0;}
		else if(k==0){
			for(auto x:A)move+=x;
			}
		else if(k<n){
			sort(A.rbegin(),A.rend());
			for(i=k;i<n;i++){
				move+=A[i];
				}
			}
			cout<<move <<"\n";
		}
