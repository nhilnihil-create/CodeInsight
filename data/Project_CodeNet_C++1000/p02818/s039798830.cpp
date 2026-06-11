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
     ll t,a,b,x,y;
     cin>>a>>b>>t;
     if(t<=a)
     {
      a=a-t;
     }else
     {
      t=t-a;
      a=0;
       b=b-t;
     }
     b=max(ll(0),b);
     cout<<a<<" "<<b<<endl;
 }