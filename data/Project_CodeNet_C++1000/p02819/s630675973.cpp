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
 int a[100006];
 int main()
 {
     int n,x,y,i,j;
     cin>>n;
         for(i=4;i<=100005;i=i+2)
    {
        a[i]=1;
    }
    for(i=3;i*i<=100005;i=i+2)
    {
        if(a[i]==0)
        {
            for(j=i*i;j<=100005;j+=i*2)
            {
                a[j]=1;
            }
        }

    }
    for(i=n;i<=100005;i++)
    {
      if(a[i]==0)
      {
        cout<<i<<endl;
        return 0;
      }
    }
 }