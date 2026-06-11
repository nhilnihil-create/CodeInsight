#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = (int)1e5 + 10;
int r[maxn], g[maxn], c[maxn];
int cmp(int a, int b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(false);
    int X, Y, A, B, C; cin>>X>>Y>>A>>B>>C;
    priority_queue <int> cll;
    for(int i = 1; i <= A; i++) cin>>r[i];
    for(int i = 1; i <= B; i++) cin>>g[i];
    for(int i = 1; i <= C; i++) cin>>c[i], cll.push(c[i]);
    sort(r + 1, r + A + 1, cmp);
    sort(g + 1, g + B + 1, cmp);
    priority_queue <int> les;
    LL ans = 0;
    for(int i = 1; i <= X; i++){
        ans += r[i];
        les.push(-r[i]);
    }
    for(int i = 1; i <= Y; i++) les.push(-g[i]), ans += g[i];
    while(!les.empty() && !cll.empty() && -les.top() < cll.top()){
        ans -= (-les.top()); les.pop();
        ans += cll.top(); cll.pop();
    }
    cout<<ans;
    return 0;
}