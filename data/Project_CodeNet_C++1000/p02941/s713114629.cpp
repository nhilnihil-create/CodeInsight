#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n, 0), b(n, 0);

    for(int i = 0; i < n; i += 1)
        cin >> a[i];
    
    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < n; i += 1) {
        cin >> b[i];
        if(a[i] != b[i])
            pq.push(make_pair(b[i], i));
    }

    int64_t sum_a = accumulate(a.begin(), a.end(), 0LL);
    int64_t sum_b = accumulate(b.begin(), b.end(), 0LL);
    
    int64_t steps = 0;

    while(sum_b > sum_a) {
        auto maxx = pq.top();
        pq.pop();

        int where = maxx.second;
        int value = maxx.first;
        
        int left = b[(where - 1 + n) % n];
        int right = b[(where + 1) % n];
        
        int diff = left + right;
        int many = (value - max(a[where], max(left, right))) / diff;
        
        if(b[where] - 1LL * (many + 1) * diff >= a[where]) {
            many += 1;
        }

        b[where] -= many * diff;
        sum_b -= many * diff;
        steps += many;
            
        if(a[where] != b[where])
            pq.push(make_pair(b[where], where));

        if(many == 0)
            break;
    } 

    if(a != b) {
        cout << "-1\n";
    } else {
        cout << steps << "\n";
    }
}