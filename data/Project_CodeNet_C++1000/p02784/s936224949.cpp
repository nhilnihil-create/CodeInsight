#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < n; i++)

int main(){
    int H, N;
    cin >> H >> N;
    vector<int> A(N);
    rep(i, N) cin >> A.at(i);
    int sum = 0;
    rep(i, N) sum += A.at(i);
    if(H <= sum) cout << "Yes" << endl;
    else cout << "No" << endl;
}