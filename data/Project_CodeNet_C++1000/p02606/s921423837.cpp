#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define ff first
#define sc second
#define pb push_back
#define full(v) v.begin(),v.end()
#define ms(a) memset(a,0,sizeof(a))
#define mod 1000000007
#define mod2 998244353
#define msb(b) memset(b,true,sizeof(b))
#define msf(b) memset(b,false,sizeof(b))
#define MAXN 100005
// bool prime[1000000]; // 10**6
// lli pri[100000],x=0;
/*void sieve()
{
  msb(prime);
  prime[0]=prime[1]=false;
  for(int p=2;p*p<=1000000;p++)
  {
    if(prime[p])
    {
      for(int i=p*2;i<=1000000;i+=p)
        prime[i]=false;
      // a[x++]=p;
    }
  }
} */

int main()
{
    fio;
    int t,n,i, l, r, d;
    cin >> l >> r >> d;
    int cnt = 0;
    f(i,l,r+1)
        if(i % d == 0)
            cnt++;
    cout << cnt << endl;
}
