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
map<int,int>m;

int main()
{
   int n,i,k,x,c=0,q;
   cin>>n>>k>>q;
   vector<int>v(n+2,(k-q));
      while(q--)
   {
    cin>>x;
    v[x]++;
   }   
   for(i=1;i<=n;i++)
   {
   // v[i]+=m[v[i]];
  //  cout<<v[i]<<" ";
    if(v[i]<=0)

    {
      cout<<"No"<<endl;
    }else
    {
      cout<<"Yes"<<endl;
    }
   }
   }