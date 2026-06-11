#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
#define int long long
#define endl '\n'
typedef long long ll;

int n,m,v,p;

bool possible(const vector<int> &arr, int x) {
    if(x <= p) return true;
    if(arr[p] - arr[x] > m) return false;
    int votes = 0;
    for(int i = 1; i <= n; ++i) {
        if(i <= (p-1)) votes += m;
        else if(i >= x) votes += m;
        else {
            votes += max(0LL, arr[x]+m - arr[i]);
        }
    }
    return votes >= m*v;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> v >> p;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin()+1,arr.end());
    reverse(arr.begin()+1,arr.end());


    //number of problems with strictly greater score is <= (p-1)
    int start = 0, end = n+1, mid;
    while(start+1 < end) {
        mid = (start + end) / 2;
        if(possible(arr, mid)) start = mid;
        else end = mid;
    }
    cout << start << endl;
}
