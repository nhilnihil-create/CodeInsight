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
  int t = 1;
  //cin>>t;
  while (t--)
  {
    long long n, mx = INT_MIN, i, j, x, y;
    cin >> n;
    int a[n+2],b[n+2];
      for(i=0;i<n;i++)
      {
        cin>>x>>y;
        a[i]=(x+y);
        b[i]=(x-y);

      }
      sort(a,a+n);
      sort(b,b+n);
      cout<<max((a[n-1]-a[0]),(b[n-1]-b[0]))<<endl;
  }
}