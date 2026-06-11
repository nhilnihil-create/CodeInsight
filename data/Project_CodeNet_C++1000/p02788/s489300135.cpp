#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int B = 500;
// バケット i は [i*B, (i+1)*B) の記録を持つ
// lazy[i] :=  バケットi の遅延を記録する
// 0 ... 加算の単位元(laze[i] == 0 ⇔ 消化しても伝播しない
//今回は本当に単位元なので例外処理的な扱いをしなくていい
vll lazy(B, 0), a(200010, 0);
 
// a_s, ..., a_t に x を加算する
void add(int s, int t, int x)
{
    // s の属するバケット, t の属するバケット
    int st = s / B, gt = t / B;

    //... || ... s ... t ... || ...
    //更新が同一パケット内で済むなら直接更新しても間に合う
    if (st == gt){
        for (int i = s; i <= t; i++) a[i] += x;
    }

    //... s ... || (被覆されるパケット) || ... t ...
    else{
        //端が属するパケット内は直接更新
        for (int i = s; i < (st + 1) * B; i++) a[i] += x;
 
        for (int i = gt * B; i <= t; i++) a[i] += x;

        //区間に被覆されるパケットについては加算を遅延に残す
        //addは結合法則を満たすのでlazyには消化されるまで何回も遅延を上乗せできる
        //該当パケットが参照されたときにlazy[i]を加算すればよい
        for (int i = st + 1; i < gt; i++){
            lazy[i] += x;
        }
    }
}
 
// a_s を返す
int find(int s){
    int st = s / B;

    // s が属するパケットの遅延を消化
    for (int i = st * B; i < (st + 1) * B; i++) a[i] += lazy[st];
    lazy[st] = 0;
    return a[s];
}

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, D, A;
    cin >> N >> D >> A;
    vector<P> p(N);
    REP(i, N) {
        cin >> p[i].first >> p[i].second;
    }
    VSORT(p);
    vll x(N), h(N);
    REP(i, N) {
        x[i] = p[i].first, h[i] = p[i].second;
    }
    ll res = 0;
    REP(i, N) {
        // 体力を削りきっていたら continue
        h[i] -= find(i) * A;
        if (h[i] <= 0) continue;
        ll b = (h[i] - 1) / A + 1; // ここで必要な爆破回数
        res += b;
        ll ub = upper_bound(ALL(x), x[i] + 2 * D) - x.begin() - 1; // 爆破が届く最遠地点の id
        add(i, ub, b);
    }
    cout << res << endl;
    return 0;
}