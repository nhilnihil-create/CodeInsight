#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
int fami(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%MOD;
		a=1ll*a*a%MOD;
		b>>=1; 
	}
	return res;
} 
int main()
{
  int n;
  cin>>n;
  cout<<((0ll+fami(10,n)-2*fami(9,n)+fami(8,n))%MOD+MOD)%MOD;


return 0;
}

