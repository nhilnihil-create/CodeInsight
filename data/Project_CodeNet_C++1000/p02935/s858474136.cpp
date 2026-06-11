#include <bits/stdc++.h>
using namespace std;

int main() {
    long double n,sum = 0,gousei;
    cin >> n;
    vector<long double> data(n);
    for (int i = 0; i < n; i++){
        cin >> data.at(i);
    }
    sort(data.begin(), data.end());
    gousei = data.at(0);
    for (int i = 0; i < n-1; i++){
        gousei = (gousei+data.at(i+1)) / 2;
    }
    cout << fixed << setprecision(10);
    cout << gousei << endl;
}