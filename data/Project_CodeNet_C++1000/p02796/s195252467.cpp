#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int N;
    cin >> N;
    vector<pair<long long, long long>> X(N);
    for (int i = 0; i < N; i++) {
        long long x, l;
        cin >> x >> l;
        X[i] = {x-l, x+l};
    }
    sort(X.begin(), X.end(), [](pair<long long, long long>a, pair<long long, long long> b){return a.second < b.second;});
    
    int ans = 0;
    long long cur = LLONG_MIN;
    for (int i = 0; i < N; i++) {
        if (cur > X[i].first){
            continue;
        }
        ans++;
        cur = X[i].second;
    }
    cout << ans << endl;
}