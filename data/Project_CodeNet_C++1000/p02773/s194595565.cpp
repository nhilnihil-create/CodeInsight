#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    int max_m = 0;
    map<string, int> M;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        M[s]++;
        max_m = max(M[s], max_m);
    }

    for(auto m:M) {
        if(m.second == max_m) {
            cout << m.first << endl;
        }
    }
}

