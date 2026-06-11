#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,sum = 0;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++){
        cin >> data.at(i);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i == j)break;
            sum += data.at(i) * data.at(j);
        }
    }
    cout << sum << endl;
}