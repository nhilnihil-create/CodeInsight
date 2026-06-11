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
#define INF 99999999999

ll p[5001];
ll c[5001];

ll calc(ll n, ll k)
{
  ll ans = -INF;
  repl(i, n)
  {
    ll tmpans = 0;
    ll sum = 0;
    ll idx = i;
    ll cnt = 0;
    ll locnt = k;

    do
    {
      sum += c[idx];
      idx = p[idx];
      cnt++;
    } while (idx != i);
    if(locnt / cnt >= 1 && sum > 0)
    {
      if(locnt % cnt > 0)
      {

        tmpans += sum * (k / cnt - 1);
        locnt %= cnt;
        locnt += cnt;
      }
      else
      {
        tmpans += sum * (k / cnt - 1);
        locnt = cnt;
      }
    }
    else
    {
      if(locnt % cnt > 0)
      {
        locnt %= cnt;
        if(k > cnt)
        {
          locnt += cnt;
        }
      }
      else
      {
        locnt = cnt;
      }
    }

    ll pt = i;
    ll vmax = -INF;
    ll vtmp = 0;
    repl(x, locnt)
    {
      vtmp += c[p[pt]];
      vmax = max(vtmp, vmax);
      pt = p[pt];
    }
    tmpans += vmax;
    ans = max(ans, tmpans);
  }

  return ans;
}

ll calc2(ll n, ll k)
{
  ll ans = -INF;

  rep(i, n)
  {
    ll tmp = 0;
    ll pt = i;
    rep(j, k)
    {
      tmp += c[p[pt]];
      pt = p[pt];
      ans = max(ans, tmp);
    }
  }
  return ans;
}

int main()
{
  ll n,k;
  cin >> n >> k;

  repl(i, n)
  {
    readVarll(tmp);
    p[i] = tmp - 1;
  }

  repl(i, n)
  {
    readVarll(tmp);
    c[i] = tmp;
  }


  // ここから確認
  // srand(time(NULL));
  // n = 5;
  // rep(i, n)
  // {
  //   p[i] = ((i+1) % n);
  // }

  // rep(x, 100)
  // {
  //   k = rand() % 99 + 1;
  //   rep(i, n)
  //   {
  //     c[i] = rand() % 201 - 100;
  //   }

  //   ll ans1 = calc(n, k);
  //   ll ans2 = calc2(n ,k);

  //   if(ans1 != ans2)
  //   {
  //     cout << "wrong" << endl;
  //     cout << n << " " << k << endl;
  //     rep(i, n) cout << (p[i]+1) << " ";
  //     cout << endl;
  //     rep(i, n) cout << c[i] << " ";
  //     cout << endl;
  //     cout << "ans1=" << ans1 << ",ans2=" << ans2 << endl;
  //   }
  // }
  //ここまで

  ll ans = calc(n, k);

  cout << fixed << ans << endl;

  return 0;
}