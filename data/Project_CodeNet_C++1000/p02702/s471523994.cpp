#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

ll ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

int main(){

    string s;
    cin >> s;

    ll n=s.size();
    ll p=2019;
    ll ans=0;

    vec a(n+1);
    ll d=1;
    for(ll i=0;i<n;i++){
      ll b=ctoi(s[n-1-i]);
      if(i!=0)d=(d*10)%p;
      a[i+1]=a[i]+d*b%p;
      a[i+1]%=p;
    }

    vec b=a,c=a;
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    for(ll i=0;i<c.size();i++){
      ll e=upper_bound(b.begin(),b.end(),c[i])-lower_bound(b.begin(),b.end(),c[i]);
      ans+=e*(e-1)/2;
    }

    cout << ans << endl;

}