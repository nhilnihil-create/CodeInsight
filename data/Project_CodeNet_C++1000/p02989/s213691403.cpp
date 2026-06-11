#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    vector<int> V(N);
    for(int i=0; i<N; i++) cin >> V[i];
    sort(V.begin(), V.end());
    cout << V[N/2] - V[N/2 - 1] << endl;
}