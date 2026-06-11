#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;scanf("%d",&n);
    n = (1<<n);
    multiset<int> ms;
    for(int i=0;i<n;++i) {
        int x;
        scanf("%d",&x);
        ms.insert(x);
    }
    priority_queue<int> pq[2];
    int bit = 0;
    pq[bit].push(*prev(ms.end()));
    ms.erase(prev(ms.end()));
    while(!ms.empty()) {
        int nbit = bit^1;
        while(!pq[bit].empty()) {
            int top = pq[bit].top();pq[bit].pop();
            pq[nbit].push(top);
            multiset<int>::iterator it = ms.lower_bound(top);
            if(it== ms.begin()) {
                printf("No\n");
                return;
            }
            it = prev(it);
            pq[nbit].push(*it);
            ms.erase(it);
        }
        bit = nbit;
    }
    printf("Yes\n");
}
int main() {
    solve();
    return 0;
}