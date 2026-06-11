#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<long long> x, std::vector<long long> y){
    auto dist = [&](int i, int j){
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        return sqrt(dx*dx+dy*dy);
    };
    vector<int> p(N);
    for(int i = 0; i < N; ++i) p[i] = i;
    double len = 0;
    int cnt = 0;
    do {
        for(int i = 0; i < N-1; ++i){
            len += dist(p[i], p[i+1]);
        }
        cnt++;
    } while (next_permutation(p.begin(), p.end()));
    double ans = len/cnt;
    printf("%.10f\n", ans);
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    solve(N, std::move(x), std::move(y));
    return 0;
}
