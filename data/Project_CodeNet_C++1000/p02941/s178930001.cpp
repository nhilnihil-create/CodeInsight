#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long int;
const int MAX_NUM = 2 * 1e5 + 10;
vector<int> a(MAX_NUM, 0);
vector<int> b(MAX_NUM, 0);
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    priority_queue<pair<int, int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i]; 
    }
    for(int i=0; i<n; i++){
        cin >> b[i]; 
        if(b[i] != a[i]){
            pq.push(pair<int, int>{b[i], i});
        }
    }
 
    ll ans = 0;
    while(!pq.empty()){
        pair<int, int> maxp = pq.top(); pq.pop();
        int val = maxp.first; int id = maxp.second;
        int l = b[(id + n - 1) % n];
        int r = b[(id + 1) % n];
        int div = ceil((val - max(max(l, r), a[id])) / double(l + r));
        val -= div * (l + r);
        ans += div;
        b[id] = val;
        // for(int i=0; i<n; i++){
        //     cout << b[i] << " ";
        // }
        // cout << endl;
        if(val == a[id]){continue;}
        else if(div <= 0){cout << -1 << endl; return 0;}
        else{
            pq.push(pair<int, int>{b[id], id});
        }
    }
 
    cout << ans << endl;
    return 0;
}