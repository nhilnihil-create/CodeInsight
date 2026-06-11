#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for (int i = 0;i < n;++i) scanf("%d",&a[i]);
    for (int i = 0;i < n;++i) scanf("%d",&b[i]);
    priority_queue<P> que;
    bool ans = true;
    ll cnt = 0;
    for (int i = 0;i < n;++i) {
        if (b[i] < a[i]) ans = false;
        else if (b[i] > a[i]) que.push(P(b[i],i));
    }
    while (ans && !que.empty()) {
        P t = que.top();
        que.pop();
        int i = t.second;
        int s = b[i-1+(i ? 0 : n)]+b[i+1-(i < n-1 ? 0 : n)];
        if (b[i]-s < a[i]) {
            ans = false;
        }
        cnt += (b[i]-a[i])/s;
        b[i] -= (b[i]-a[i])/s*s;
        t.first = b[i];
        if (t.first > a[i]) {
            que.push(t);
        }
    }
    cout << (ans ? cnt : -1) << endl;
    return 0;
}