
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long int
#define FOR(i,a,b) for(ll (i)=(a);i<(ll)(b);i++)
#define rep(i,n) FOR(i,0,n)
#define rep1(i,n) FOR(i,1,n)
#define outi(a) printf("%lld\n",(a))
#define prial(a) cout << a << endl;
#define line cout << endl;
#define pb push_back
using namespace std;
inline ll read()
{
    ll x=0; static int p; p=1; static char c; c=getchar();
    while (!isdigit(c)) { if (c=='-') p=-1; c=getchar(); }
    while ( isdigit(c)) { x=(x<<1)+(x<<3)+(c-48); c=getchar(); }
    x*=p;
    return x;
}
//****************************
map<int, int>exist;
//****************************
int solve(int i);
int main()
{
  int n = read();
  ll sum =0;
  rep(i,n) sum ^= read();
  if(sum==0) cout << "Yes"<< endl;
  else
  cout<<"No"<<endl;
}
