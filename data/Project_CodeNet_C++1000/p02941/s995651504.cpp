#include<cstdio>
#include<queue>
#include<algorithm>
#define st first
#define nd second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 2e5 + 10;

int a[N], b[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    a[0] = a[n];
    priority_queue<pii> pq;
    for(int i = 1; i <= n; i++){
        scanf("%d", &b[i]);
        if(b[i] != a[i])
            pq.push({b[i], i % n});
    }
    b[0] = b[n];
    ll ans = 0;
    while(!pq.empty()){
        pii p = pq.top();
        pq.pop();
        int x = (p.nd + 1) % n, y = (p.nd - 1 + n) % n;
        if(b[x] + b[y] >= b[p.nd]) return !printf("-1");
        int sum = b[x] + b[y] ;
        int ma = max(a[p.nd], sum);
        int k = (b[p.nd] - ma + sum - 1) / sum;
        b[p.nd] -= sum * k;
        if(b[p.nd] < a[p.nd]) return !printf("-1");
        ans += k;
        if(b[p.nd] != a[p.nd]) pq.push({b[p.nd], p.nd});
    }
    printf("%lld", ans);


}
