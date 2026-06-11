#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb                 push_back
#define bug(x)             cerr<<#x<<" "<<x<<endl;
#define T int time;        scanf("%d", &time); while(time--)
    vector<ll>ar;
  bool check(ll i,ll n){
    if(abs(i-n)<=1)return true;
    for(ll ii=n-1; ii>i; ii--)if(ar[ii]<ar[ii-1])
      cout<<ar[ii]<<" ";
    cout<<endl;
    return true;
  }

   int main(){
        string s1,s2;
        cin>>s1>>s2;
        ll n,m;
        cin>>n>>m;
        string u;
        cin>>u;
        if(u==s1)n--;
        else m--;
        cout<<n<<" "<<m<<endl;
     }
   