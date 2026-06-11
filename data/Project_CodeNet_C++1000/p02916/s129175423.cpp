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
    int ar[n];
    int a[n];int a2[n];
    int c=0;
    REP(i,n)
    cin>>ar[i];
    REP(i,n)
    cin>>a[i];
    REP(i,n-1)
    cin>>a2[i];
    REP(i,n)
   c+=a[ar[i]-1];
   REPS(i,n-1)
   {
       if(ar[i]==ar[i-1]+1)
       c+=a2[ar[i-1]-1];
   }
   cout<<c<<endl;
}