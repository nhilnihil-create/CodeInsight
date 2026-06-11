#include<bits/stdc++.h>
#define pi acos(-1)
#define mx 1000000000
#define mod 1000000009
#define pii pair<int,int>
#define psi pair<string,int>
#define vi vector<int>
typedef long long ll;
using namespace std;
void fastio()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif
    fastio();
    int i,j,t,n,m,r;
    //cin>>t;
    //while(t--){
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
    int c=1;
    int mn=a[0];
    for(i=1;i<n;i++){
      if(a[i]<mn){
        c++;
        mn=a[i];
      }
    }
    cout<<c<<endl;
    //}
 return 0;
}

