#include<bits//stdc++.h>
using namespace std;
typedef long long ll;
#define req(i,n) for(int i = 1;i <= n;i++)
#define ALL(a)  (a).begin(),(a).end()
ll n,m, ans = 0;
int main() {
    cin >> n >> m; priority_queue<int> pq; int a, b,j =0;
    vector<pair<int, int>> v;
    req(i, n) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }sort(ALL(v));
    req(i, m) {
        for(;j < n;j++)  {
            if (v[j].first <= i) {
                pq.push(v[j].second); continue;
            }
            break;
        }
        if (!pq.empty()) ans += pq.top(), pq.pop();
    }
    cout << ans << endl;
}