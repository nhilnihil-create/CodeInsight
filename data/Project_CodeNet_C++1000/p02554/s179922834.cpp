#include<bits/stdc++.h>
using namespace std;
long long int MOD=1000000007;
long long int fun(long long int a,long long int n)
{ long long int res=1;
 while(n)  
 { if(n%2==1)
 { res=(res*a) % MOD;
  n--; }
  a=(a*a) % MOD;
  n/=2;
 }
 return res;
}
int main()
{long long int N;
 cin>>N;
 long long int X=fun(10,N)-fun(9,N)-fun(9,N)+fun(8,N);
 X=X % MOD;
 X=(X+MOD) % MOD;
 cout<<X;
}