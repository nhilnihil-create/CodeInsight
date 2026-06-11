#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long int
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pci pair<char,int
#define mii map<int,int>
#define mll map<long long int,long long int>
#define mci map<char,int>
#define umii unordered_map<int,int>
#define umll unordered_map<long long int,long long int>
#define umci unordered_map<char,int>
#define F first
#define S second
#define pb push_back
#define endl '\n'
#define mod 1000000007
using namespace std;
#define maxval 10003000

int main(){
   IOS;
ll t;t=1;//cin>>t;

while(t--){
ll n;cin>>n;ll x=1;ll a[n];ll ans[n];
for(ll i=0;i<n;i++){
    cin>>a[i];
}
for(ll i=0;i<n;i++) ans[i]=i+1;
ll a1;
while(1){ll y=0;
    for(ll i=0;i<n;i++) {
        if(a[i]!=ans[i]) {y=1;break;}
    }
    if(y==0) {
        a1=x;break;
    }
    x++;
    next_permutation(ans,ans+n);
}
x=1;ll b[n];//ll ans[n];
for(ll i=0;i<n;i++){
    cin>>b[i];
}
for(ll i=0;i<n;i++) ans[i]=i+1;
ll b1;x=1;
while(1){ll y=0;
    for(ll i=0;i<n;i++) {
        if(b[i]!=ans[i]) {y=1;break;}
    }
    if(y==0) {
        b1=x;break;
    }
    x++;
    next_permutation(ans,ans+n);
}
  cout<<abs(b1-a1)<<"\n";  
} 
    

    
return 0;    
}
