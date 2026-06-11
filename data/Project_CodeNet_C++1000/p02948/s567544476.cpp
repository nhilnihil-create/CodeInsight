#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
pair<int, int> ab[100000];
priority_queue<int> pq;

int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        ab[i] = make_pair(a, b);
    }
    sort(ab, ab + n);
    int j = 0;
    int ans = 0;
    for (int i = 1; i <= m; i++){
        while ((ab[j].first <= i) && (j < n)){
            pq.push(ab[j].second);
            j++;
        }
        if (!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
}
