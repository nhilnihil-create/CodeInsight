#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int A[1];
int size=1;
int m=2;
#define N 101
#define mod 1000000007
#define f(i,n) for(int i=0;i<n;i++)
#define in(i,arr) for(auto &i:arr)cin>>i;


int main() {
    fast;
    int t=1;
    //cin >> t;
    while (t--)
    { int l,r,d,count=0;
      cin>>l>>r>>d;
      for(int i=l;i<=r;i++)
      if(i%d==0)
          count++;
      cout<<count;





    }
}
