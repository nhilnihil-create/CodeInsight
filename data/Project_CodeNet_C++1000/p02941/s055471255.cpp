#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, a[200010], b[200010];
int norm(int x){
    x = ((x % n) + n) % n;
    return x? x: n;
}
int& A(int i){ return a[norm(i)]; }
int& B(int i){ return b[norm(i)]; }
bool f(int i){ return B(i) >= B(i - 1) + B(i + 1) + A(i); }

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);

    priority_queue<pii> q;
    long long ans = 0;
    for(int i = 1; i <= n; i++) if(f(i)) q.push({B(i), i});
    while(!q.empty()){
        int i = q.top().second; q.pop();
        int k = (B(i) - A(i)) / (B(i - 1) + B(i + 1));
        if(!k){ puts("-1"); return 0; }
        ans += k;
        B(i) -= k * (B(i - 1) + B(i + 1));
        if(f(i - 1)) q.push({B(i - 1), i - 1});
        if(f(i + 1)) q.push({B(i + 1), i + 1});
    }
    for(int i = 1; i <= n; i++) if(A(i) != B(i)){ puts("-1"); return 0; }
    printf("%lld", ans);
    return 0;
}