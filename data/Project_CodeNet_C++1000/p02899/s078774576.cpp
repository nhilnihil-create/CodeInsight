#include<bits/stdc++.h>

#define faster     ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define read       freopen("input.txt", "r", stdin);
#define write      freopen("output.txt", "w", stdout);
#define endd        '\n'
#define ll         long long
#define sq(a)      ((a) * (a))

using namespace std;
int main()
{
      faster;
      double pi = 2 * acos(0.0);
      ll int n,i,t,j,k,m=0,a,b,c,d,p,q,r,x=250,y=10,z,count=0;
      cin>>n;
      ll int ara[n+1]={};
      for(i=1;i<=n;i++){
            cin>>a;
            ara[a]=i;
      }
      for(i=1;i<=n;i++){
            cout<<ara[i]<<" ";
      }
      return 0;
}
//Sheikh Tafsir Rahman
//CSE IUT