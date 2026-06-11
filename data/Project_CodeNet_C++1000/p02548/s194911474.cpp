#include <bits/stdc++.h>
#define forna(i,a,n) for(int i=a;i<n;i++)
typedef long long int lli;
#define MOD 1000000007
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
lli t,n,m,tot=0;string s;
cin>>n;
forna(i,1,n+1){
  forna(j,1,n+1){
    if(i*j>n-1) break;
    tot++;
  }
}
cout<<tot<<endl;
}
