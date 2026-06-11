#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb                 push_back
#define bug(x)             cerr<<#x<<" "<<x<<endl;
#define T int time;        scanf("%d", &time); while(time--)

   int main(){
        ll n,m;
        cin>>n>>m;
      ll r=min(n,m);
      ll rr=max(n,m);
      for(ll i=0; i<rr; i++)cout<<r;
        cout<<endl;

     }
   