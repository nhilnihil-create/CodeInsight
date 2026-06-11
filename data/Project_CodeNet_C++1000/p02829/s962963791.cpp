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
    int a1,b;
       cin>>a1>>b;
       a[a1]=1;a[b]=1;
       for(int i=1;i<=3;i++)
       {
        if(a[i]==0)  
        {
          cout<<i<<endl;
        }
    }
  }
 
  return 0;
}