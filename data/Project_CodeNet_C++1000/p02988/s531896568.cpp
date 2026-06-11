#include <bits/stdc++.h>
using namespace  std;

int main(){

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i=0; i<n; i++){
        cin >> p.at(i);
    }

    int cnt = 0;
    for (int i=0; i<n-2; i++){
        if ((p.at(i) < p.at(i+1)) && (p.at(i+1) < p.at(i+2))){
            cnt++;
        }
        if ((p.at(i) > p.at(i+1)) && (p.at(i+1) > p.at(i+2))){
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}