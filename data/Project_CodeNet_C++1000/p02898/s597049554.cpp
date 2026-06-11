#include "bits/stdc++.h"
using namespace std;
const int MAXN=1e5+1,OO=0x3f3f3f3f;
typedef  long long ll;
int main(){
int n,k,ans=0,x; cin>>n>>k;
  while(n--)
      cin>>x,ans+=(x>=k);
  cout<<ans;
}