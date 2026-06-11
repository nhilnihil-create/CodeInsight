#include <bits/stdc++.h>
#include <set>
#include <queue>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++) 
#define reps(i, s, n) for (int i = s; i < (int)(n); i++) 
#define ll long long
#define ld long double
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++) 
#define repsl(i, s, n) for (ll i = s; i < (ll)(n); i++)  
#define outdeb(fir, sec, thr) cout << fir << ":" << sec << ":" << thr << endl
#define readVarll(nam) ll nam; cin >> nam

ll x[20],y[20];
ll n;

double calc1()
{
  int tmp[n];

  rep(i, n)
  {
    tmp[i] = i;
  }

  double sum = 0;
  int cnt = 0;
  do{
    
    reps(i, 1, n)
    {
      sum += sqrt(pow(x[tmp[i]] - x[tmp[i-1]], 2) + pow(y[tmp[i]] - y[tmp[i-1]], 2));
    }
    cnt++;
  }while(next_permutation(tmp, tmp+n));

  return sum / cnt;
}

int main()
{
  cin >> n;
  
  repl(i, n)
  {
    cin >> x[i] >> y[i];
  }
 
  cout << fixed << setprecision(15) << calc1() << endl;
  return 0;
}