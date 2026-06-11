#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

int main(){
    int N;
    cin >> N;
    vector<double> v(N); //価値
    rep(i, N) cin >> v[i];

    sort(v.begin(), v.end());

    double tmp;
    rep(i, N-1){
        tmp = (v[i]+v[i+1]) / 2.0;
        v[i+1] = tmp;
    }

    cout << tmp << endl;

    return 0;
}