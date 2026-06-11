#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )
typedef std::pair<int,int> pint;

using namespace std;
typedef long long ll;

double calc(pint a,pint b){
    int diff1,diff2;
    diff1 = a.first - b.first;
    diff2 = a.second - b.second;
    double tmp = pow(diff1,2) + pow(diff2,2); 
    return sqrt(tmp);
}

int main(){

    int N; cin >> N;
    vector<int> v(N);
    vector<pint> z(N+5);
    double sum = 0;
    rep (i,N){
        int tmp1;
        int tmp2;
        cin >> tmp1 >> tmp2;
        z[i+1].first = tmp1;
        z[i+1].second = tmp2;
    }
    vector<vector<int>> list;
    iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
    do {
        rep (i,N-1){
            sum += calc(z[v[i]],z[v[i+1]]);
        }
    } while( next_permutation(v.begin(), v.end()) );     // 次の順列を生成
    rep (i,N){
        sum /= (double)(i+1);
    }
    cout << fixed <<setprecision(12) << sum << endl;
    return 0;
}