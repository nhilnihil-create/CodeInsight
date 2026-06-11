#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
int n, m, f[200009], g[200009], st[200009], top = 0;
char str[200009];
struct node {
    int v, id;
};
deque<node> q;

int main() {
    memset(g, -1, sizeof(g));
    memset(f, 0x3f, sizeof(f));
    scanf("%d%d", &n, &m);
    scanf("%s", str);
    f[0] = 0, q.push_back({f[0], 0});
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && i - q.front().id > m)q.pop_front();
        if (str[i] == '1')continue;
        if (!q.empty())f[i] = q.front().v + 1, g[i] = q.front().id;
        while (!q.empty() && q.back().v > f[i])q.pop_back();
        if (f[i] != 0x3f3f3f3f)q.push_back({f[i], i});
    }
    if (g[n] == -1)return puts("-1"), 0;
    int now = n;
    while (g[now] != -1) { st[++top] = now - g[now], now = g[now]; }
    while (top) {
        printf("%d ", st[top--]);
    }
    puts("");
    return 0;
}