#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >>q;
    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; i++){
        data.at(i) = make_pair(i,k);
    }
    for (int i = 0; i < q; i++){
        int a;
        cin >> a;
        data.at(a-1).second ++;
    }
    for (int i = 0; i < n; i++){
        if(data.at(i).second > q){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}