#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define ll long long
int main() {
    int n;
    cin>>n;
    int ar[n-1];
    REP(i,n-1)
    cin>>ar[i];
    ll c=0;
   if(n==2)
   {cout<<2*ar[0]<<endl;return 0;}
    for(int i=0;i<n-1;i++)
    {
        if(i==0)
        {c+=ar[i];continue;}
        
        c+=min(ar[i],ar[i-1]);
       
    } c+=ar[n-2];
    cout<<c<<endl;
}