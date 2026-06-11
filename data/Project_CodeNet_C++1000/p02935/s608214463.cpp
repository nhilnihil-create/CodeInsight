#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    
    int N;
    cin >> N;
    int v[N];
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v, v+N);
    vector<double> d;
    double ans = 0.0;
    for(int i = 0; i < N - 1; i++){
        if(i == 0){
            d.push_back((v[i] + v[i+1]) / 2.0);
            ans = (v[i] + v[i+1]) / 2.0;
        } else {
            double tmp = (d[i-1] + v[i+1]) / 2.0;
            d.push_back(tmp);
            ans = tmp;
        }
    }
        printf("%20.20f\n",ans);
    
    return 0;
}