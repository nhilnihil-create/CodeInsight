#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mp  make_pair
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int a[5];
int main()
{
  int t=1;
  //cin>>t;
  while(t--)
  {
     string s,t,ans;
     int i,n,j;
     cin>>n;
     cin>>s>>t;
     for(i=0;i<n;i++)
     {
      cout<<s[i]<<t[i];
     }
  } 
  cout<<endl;
 
  return 0;
}