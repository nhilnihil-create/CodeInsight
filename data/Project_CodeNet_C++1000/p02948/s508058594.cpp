#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll n, m;
    cin >> n >> m;

    // mem[x] : x 日後に報酬がもらえる仕事の集合. 値は報酬額
    vvll mem(m + 1);
    ll a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a > m) continue; // 最速で始めても M 日目に間に合わない仕事は無視
        mem[a].push_back(b);
    }

    // 期限がカツい日にできる仕事は限定的なので後ろ側からどの仕事をいれたら良いか考える
    // que : その日入れられる仕事の報酬リスト
    // mem を参照してギリ M 日目に間に合う案件の報酬を que に追加していく
    priority_queue<ll> que;
    ll res = 0;
    for (int d = m - 1; d >= 0; d--) {
        // mem[m - d] : d 日目に始めたらちょうど M 日目に報酬が降ってくる仕事の集合(b はその個々の報酬額)
        for (auto b : mem[m - d]) que.push(b);
        if (!que.empty()) {
            res += que.top();
            que.pop();
        }
    }
    cout << res << endl;
    return 0;
}