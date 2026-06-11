#include <bits/stdc++.h>
using namespace std;

#define INPUT freopen("input.txt", "r", stdin);

#define ll long long
#define ld long double

#define len(s) s.size()

#define fl(st, en, in) for (int i = st; i < en; i += in)
#define rfl(st, en, de) for (int i = st; i < en; i -= de)
#define fll fl(0, n, 1)

#define cy cout << "Yes" << endl;
#define cn cout << "No" << endl;
#define ci(s) cin >> s
#define co(s) cout << s << endl

#define vl vector<ll>
#define pb(x) push_back(x)

#define ms(arr, x) memset(arr, x, sizeof(arr))

#define inf INT_MAX

int main()
{
    //INPUT;

    ll n, m;
    ci(n);
    ci(m);
    ll ar[n];
    ll cost[n];
    ll lt[n];
    ll ans = -inf;
    ms(lt, 0);
    fll
    {
        ci(ar[i]);
    }
    fll
    {
        ci(cost[i]);
    }
    fll
    {
        ll st = ar[i];
        ll en = ar[i];
        ll cnt = 0;
        vl vec;
        //co("looping...");
        ll sum = 0;
        while (true)
        {
            sum += cost[st - 1];
            vec.pb(sum);
            ll tm = ar[st - 1];
            cnt++;
            if (tm == en)
            {
                break;
            }
            st = tm;
        }
        lt[i] = cnt; //f
        ll temp_ans = -inf;
        //cout << "count = " << cnt << endl;
        if (m <= cnt)
        {
            fl(0, m, 1)
            {
                temp_ans = max(temp_ans, vec[i]);
            }
        }
        else
        {
            ll d = m / cnt;
            ll r = m % cnt;
            ll chashed = -inf;
            if (vec[len(vec) - 1] >= 0)
            {
                chashed = d * vec[len(vec) - 1];
                temp_ans = chashed;
                fl(0, r, 1)
                {
                    temp_ans = max(temp_ans, vec[i] + chashed);
                }
                ll tm2 = -inf;
                fl(0, cnt, 1)
                {
                    tm2 = max(tm2, vec[i]);
                }
                ll tm3 = chashed;
                fl(0, cnt, 1)
                {
                    tm3 = max(tm3, vec[i] + chashed - vec[len(vec) - 1]);
                }
                temp_ans = max(max(temp_ans, tm2), tm3);
            }
            else
            {
                fl(0, len(vec), 1)
                {
                    temp_ans = max(temp_ans, vec[i]);
                }
            }
        }
        ans = max(ans, temp_ans);

        fl(0, len(vec), 1)
        {
            //cout << vec[i] << " ";
        }
        //cout << endl;
    }
    co(ans);
    //co("Here is the number of elements");
    fll
    {
        // co(lt[i]);
    }
}