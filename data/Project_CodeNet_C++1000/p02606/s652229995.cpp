#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 10000001
#define mod 1000000007

ll computeTotient(ll n)
{
    ll res=n;
    ll tmp=n;
    for(int i=2;i<=sqrt(tmp);i++)
    {
        if(n%i==0){
            res-=(res/i);
            while(n%i==0)
                n/=i;
        }

    }
    if(n>1)
    {
        res-=(res/n);
    }
    return res;

}
int main()
{
   int l,r,d;cin >> l >> r >> d;
  int c=0;
  for(int i=l;i<=r;i++)
  {
    c+=(i%d==0); 
  }
  cout<<c<<'\n';
} 
