#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long N;
vector<long long> A;

void solve(){
    vector<long long> plus, minus;

    for(long long i = 0; i < N; i++){
        if(A[i] >= 0) plus.push_back(A[i]);
        else minus.push_back(A[i]);
    }

    sort(plus.begin(), plus.end(), greater<long long>());
    sort(minus.begin(), minus.end());

    if(minus.empty()) minus.push_back(plus.back()), plus.pop_back();
    if(plus.empty()) plus.push_back(minus.back()), minus.pop_back();

    vector<pair<long long, long long> > res;
    long long cur = minus[0];
    for(long long i = 0; i < plus.size()-1; i++){
        res.push_back(make_pair(cur, plus[i]));
        cur -= plus[i];
    }
    res.push_back(make_pair(plus.back(), cur));
    cur = plus.back() - cur;

    for(long long i = 1; i < minus.size(); i++){
        res.push_back(make_pair(cur, minus[i]));
        cur -= minus[i];
    }

    cout << cur << endl;

    for(long long i = 0; i < res.size(); i++){
        cout << res[i].first << " " << res[i].second << endl;
    }
}
int main(){
    cin >> N;
    A.resize(N);

    for(long long i = 0; i < N; i++) cin >> A[i];

    solve();
    return 0;
}