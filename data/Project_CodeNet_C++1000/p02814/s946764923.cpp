#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

long long LCM(long long a, long long b) {
    return a / GCD(a, b) * b;
}

int main()
{ ll n,m;
    cin>>n>>m;
  vector<int>a(n);
  ll lcm=1;
    rep(i,n)
    {ll ai;
    cin>>ai;
    a.at(i)=ai;
    lcm=LCM(lcm,ai);
    //cout << i<<endl;
    }
    lcm/=2;
   // cout << lcm<<endl;
    ll count=0;
    for (ll i = 1; i*lcm <= m; i+=2)
    {
        count++;
      //  cout << i*lcm<<endl;
    }
    rep(i,n)
    {
      if(lcm*2/a[i]%2==0)
      {count=0;}
    }
    cout << count <<endl;
    return 0;
}
