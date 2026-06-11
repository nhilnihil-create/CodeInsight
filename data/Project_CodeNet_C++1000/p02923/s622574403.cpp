#include<bits/stdc++.h>
using namespace std;
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

int main()
{
  int t;
  t=1;
  //cin>>t;
  
  while(t--)
  {
    long long n,i,j,x,y,c=0,mx=0;
    cin>>n;
    int a[n+3];
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n-1)
    {
      if(a[i]>=a[i+1])
      {
        c++;
      }else
      {
        mx=max(c,mx);
        c=0;
      }
    }
    mx=max(c,mx);
    cout<<mx<<endl;
  }

}
