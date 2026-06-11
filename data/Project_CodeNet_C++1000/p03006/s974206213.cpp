#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;
int main(){
    int N;
    cin >> N;
    vector<P> x(N);
    for(int i = 0; i < N; i++) {
        long long x1, y1;
        cin >> x1 >> y1;
        x[i] = P(x1, y1);
    }
    sort(x.begin(), x.end());
    map<P, long long> m;
    for(int i = 0; i < N; i++){
        for(int j = i + 1 ; j < N; j++){
            long long s = x[j].first - x[i].first;
            long long t = x[j].second - x[i].second;
            m[P(s, t)]++;
        }
    }
    long long ans = 0;
    long long M = 0;
    for(auto v: m){
        M = max(M, v.second);
    }
    ans = N - M;
    cout << ans << endl;
}