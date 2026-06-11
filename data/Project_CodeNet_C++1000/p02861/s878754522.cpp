#include <bits/stdc++.h>
#define rep(i, n)  for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

double dist(P a, P b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main(){
    int N; cin >> N;
    vector<P> vec;
    rep(i,N){
        int x,y; cin >> x >> y;
        vec.push_back(P(x,y));
    }
    sort(vec.begin(), vec.end());
    double ans;
    int i = 0;
    do{
        double total = 0;
        rep(i,N-1) total += dist(vec[i], vec[i+1]);
        ans = (ans*i + total)/(i+1);
        ++i;
    }while(next_permutation(vec.begin(), vec.end()));
    printf("%.10f\n", ans);
}
