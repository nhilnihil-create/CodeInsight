#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int,int>pi;
typedef     pair<long long,long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mp  make_pair
#define     FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)

int main()
{
   int n,i,j,x,y,c=0;
   cin>>n;
    vi v;
    FOR(i,1,n)
    {
      cin>>j;
      v.push_back(j);
    }
    sort(all(v));
     FOR(i,0,n-3)
     {
      FOR(j,i+1,n-2)
      {
        x=lower_bound(v.begin()+j+1,v.end(),v[i]+v[j])-v.begin();
        c+=(x-j-1);
      }

     }
     cout<<c<<endl;
      
   }