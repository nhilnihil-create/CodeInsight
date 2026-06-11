#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using str = string;
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;

int main() {
    int N;
    cin >> N;
    str S;
    cin >> S;
    int R = 0, B = 0, G = 0 ;

    for(int i = 0; i < N; i++) {
        if(S[i] == 'R') R++;
        if(S[i] == 'B') B++;
        if(S[i] == 'G') G++;
    }
    ll count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int k = 2*j - i;
            if(k >= N) continue;
            if(S[i] == S[j] || S[j]== S[k] || S[k] == S[i]) continue;
            count++;
        }
    }
    cout << (ll)R*B*G - count << endl;
}
