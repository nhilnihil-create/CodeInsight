#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,t,m,x,y,q;
int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cin>>n;
      ll a[n],x=1,ans=0;
      for(int i=0;i<n;i++){
      	cin>>a[i];
      	if(a[i]==x)x++;
      	else ans++;
      }
      if(ans==n)cout<<-1<<endl;
      else cout<<ans;
}