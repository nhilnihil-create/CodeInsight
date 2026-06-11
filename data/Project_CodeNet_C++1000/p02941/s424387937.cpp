#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
    int n;
    cin >> n;
    ll a[200005], b[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    priority_queue<P> que;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        que.push(P(b[i], i));
    }
    ll ans = 0;
    int l = -1;
    while(que.size()){
        P p = que.top();
        que.pop();
        int i = p.second;
        if(i == l){
            cout << -1 << endl;
            return 0;
        }
        l = i;
        ll l = b[(i + n - 1) % n], r = b[(i + 1) % n];
        ll c = (b[i] - a[i]) / (l + r);
        ans += c;
        b[i] -= c * (l + r);
        if(b[i] != a[i]) que.push(P(b[i], i));
    }
    cout << ans << endl;
}
