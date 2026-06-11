#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    long long int sum = 0;
    cin >> N; 
    for (int i = 0; i < N.size(); ++i) {
        sum += (N.at(i) - '0');
    }
    if (sum % 9 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}