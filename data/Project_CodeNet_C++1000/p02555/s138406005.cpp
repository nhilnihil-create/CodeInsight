/******************************************
* AUTHOR : SOMU KUMAR *
* INSTITUTION : IIT BHUBANESWAR *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define MOD 1000000007
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//code here...............//
int s;
cin>>s;
ll dp1[s+1];
memset(dp1,0,sizeof(dp1));
for(int i=3;i<=s;i++){
	for(int j=3;j<=s;j++){
		if(i-j==0)dp1[i]=(dp1[i]+1)%MOD;
		else if(i-j>0)dp1[i]=(dp1[i]+dp1[i-j])%MOD;
	}
}
cout<<(dp1[s])%MOD<<endl; 
return 0;
}