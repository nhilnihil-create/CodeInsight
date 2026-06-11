#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define rep(i,x) for(long long i=0;i<(long long)(x);i++)
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define ll long long
int main() {
    int n;
    cin>>n;
    ll ar[n+1];
    ll a[n];
    REP(i,n+1)
    cin>>ar[i];
    REP(i,n)
    cin>>a[i];
    ll p=0,c=0,c1=0;
    REP(i,n)
    {
    p=min(a[i],ar[i]);
    c1=min(ar[i+1],a[i]-p);
    ar[i+1]-=c1;
    c+=p+c1;
    
}
cout<<c<<endl;
}