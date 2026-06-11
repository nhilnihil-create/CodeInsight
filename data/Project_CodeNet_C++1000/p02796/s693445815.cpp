#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long> X(n);
    vector<long> L(n);

    for(int i=0; i<n; i++){
        cin >> X[i];
        cin >> L[i];
    }

    vector<pair<long, long>> armpoint(n);
    for(int i=0; i<n; i++){
        armpoint[i] = pair<long, long>(X[i] + L[i], X[i] - L[i]);
    }
    sort(armpoint.begin(), armpoint.end());
    int ans = 0;
    int con_l = -1000000000;
    for(int i=0; i<n; i++){
        if(con_l <= armpoint[i].second){
            ans++;
            con_l = armpoint[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}
