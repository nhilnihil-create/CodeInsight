#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm> // sort
#include <math.h>
#include <map>
#include <set>

#define DEBUG 0

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
                    //999999997000000003
                    //1000000000000000000

using namespace std;

const ll A = 1000005;

ll euclidean_gcd(ll a, ll b) {
  if(a < b) return euclidean_gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b; //あまりが0ならそれが、最大公約数
}

int solve(){
    ll N;
    cin >> N;
    vector <ll> a(N,0);
    string pc = "pairwise coprime";
    string sc = "setwise coprime";
    string nc = "not coprime";

    vector <ll> c(A,0);
    REP(i,N)
    {
        cin >> a[i];
        c[a[i]]++; 
    }

    bool pairwise = true;
    for(int i = 2; i < A; i++)
    {
        int cnt = 0;
        //iの倍数が複数あったらアウト
        for(int j = i; j < A; j+=i)
        {
            cnt += c[j];
        }
        if(cnt > 1)
        {
            pairwise = false;
        }
    }
    if(pairwise)
    {
        cout << pc << endl;
        return 0;
    }

    int g = a[0];
    for(int i = 1; i < N; ++i)
    {
        g = euclidean_gcd(g,a[i]);
    }
    if(g == 1)
    {
        cout << sc << endl;
        return 0;
    }

    cout << nc << endl;

    return 0;
}

int main()
{
    solve();
    return 0;
}
