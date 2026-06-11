//-fexec-charset=CP932
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100
#define THOU 1000
#define FIVEMAX 100000
#define NINEMAX 1000000000
#define TWEMAX 1000000000000
#define rep(i,n) for (int i=0;i<n;i++)
#define drep(i,n) for(int i=n-1;i>=0;i--)
#define arep(i,a,n) for(int i=a;i<n;i++)
#define darep(i,a,n) for(int i=n,i>=a;i--)

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

ll gcd(ll x,ll y){
    if(x<y) swap(x,y);
 
    ll r;
    while(y>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main(){
  ll a,b;
  vector<ll>v;
  cin>>a>>b;
  ll x=gcd(a,b);
  const auto &pmf=prime_factorize(x);
  cout<<pmf.size()+1<<endl;
  return 0;
}