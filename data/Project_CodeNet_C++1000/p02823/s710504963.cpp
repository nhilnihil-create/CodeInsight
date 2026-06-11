#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define read(a)  for(int i = 0; i < n; i++) cin >> a[i];
#define print(a)  for(int i = 0; i < n; i++) cout << a[i] << " ";
#define pb push_back
#define ins insert
#define pql priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define pqlv priority_queue<vi>
#define pqsv priority_queue<vi, vvi, greater<vi>>
#define endl '\n'

signed main() {
    int n, a, b;
    cin >> n >> a >> b;
    if(a % 2 == b % 2) {
        cout << (b - a) / 2;
    }
    else {
        int must = min({ a - 1, n - b });
        cout << must + 1 + (b - a - 1) / 2;
    }
}