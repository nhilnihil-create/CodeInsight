#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, d, ans = 0;
    cin >> n >> k ;
    vector<int> vec(n, 0);

    for (int i = 0; i < k; i++){
        cin >> d;
        vector<int> sna(d, 0);
        for (int j = 0; j < d; j++) {
            cin >> sna.at(j);
            vec.at(sna.at(j)-1)++;
        }
    }
    for (int i = 0; i < n; i++){
        if (vec.at(i) == 0) ans++;
    }

    cout << ans << endl;

}