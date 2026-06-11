#include <bits/stdc++.h>

#define FILE
#define fr first
#define se second

using namespace std;

const long long N = 2e5 + 7;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;

int n;
int D;
int A;
pair<int, int> a[N];
queue<pair<int, long long>> q;
int main()
{
    #ifdef FILEs
        freopen("input.txt", "r", stdin);
        /// freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    cin >> n >> D >> A;
    for(int i = 1; i <= n; i ++){
        cin >> a[i].fr >> a[i].se;
    }
    long long res = 0;
    long long  damage = 0;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++){
        while(!q.empty() && a[i].fr > q.front().fr){
            damage -= q.front().se;
            q.pop();
        }
        long long hp = a[i].se - damage;
        if(hp > 0){
            long long bombs = (hp + A - 1) / A;
            res += bombs;
            damage += bombs * A;
            q.push({a[i].fr + 2 * D, bombs * A});
        }
    }
    cout << res << "\n";
}

