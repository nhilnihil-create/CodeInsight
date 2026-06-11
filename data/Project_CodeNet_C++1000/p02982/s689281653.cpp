#include <bits/stdc++.h>
using namespace std;
int N,D;
bool dist_int(vector<vector<int>> &X, int &s, int &t){
    int dist_square = 0;
    for (int i=0; i<D; ++i) dist_square += pow((X[s][i] - X[t][i]), 2);
    return (pow(((int)sqrt(dist_square*1.0)), 2)==dist_square) ? true : false;
}
int main() {
    cin >> N >> D;
    vector<vector<int>> X(N, vector<int>(D));
    for (int i=0; i<N; ++i) for (int j=0; j<D; ++j) cin >> X[i][j];
    int res = 0;
    for (int s = 0; s<N-1; ++s) for (int t=s+1; t<N; ++t) {
        if (dist_int(X, s, t)) res++;
    }
    cout << res << endl;
    return 0;
}