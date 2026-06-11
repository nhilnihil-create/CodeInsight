#include <bits/stdc++.h>
using namespace std;

int main(){
    int X, N;
    cin >> X >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {cin >> P.at(i);}
    
    bool judge = false;
    int i = 0;
    int ans = 0;
    while (!(judge)) {
        if (!(find(P.begin(), P.end(), X + i) != P.end())) {
            ans = X + i;
            judge = true;
        }
        if (!(find(P.begin(), P.end(), X - i) != P.end())) {
            ans = X - i;
            judge = true;
        }
        i++;
    }
    cout << ans << endl;
}
