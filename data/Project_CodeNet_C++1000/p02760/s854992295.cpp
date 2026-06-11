#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = acos(-1) ;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw				"\n"


int main(void)
{
	CIN;
	//ll tc,l,k,sum=0,x=0,y,z=0,m=1,n=0,ans=0;
	  int a[9],n,b; for(int i=0;i<9;i++) cin>>a[i];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>b;
    for(int& i:a) if(i==b) i=0;
  }
  cout<<(!(a[0]+a[1]+a[2])||!(a[3]+a[4]+a[5])||!(a[6]+a[7]+a[8])||!(a[0]+a[3]+a[6])||!(a[1]+a[4]+a[7])||!(a[2]+a[5]+a[8])||!(a[0]+a[4]+a[8])||!(a[2]+a[4]+a[6])?"Yes":"No");

}
