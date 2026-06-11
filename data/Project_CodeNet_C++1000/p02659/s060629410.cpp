#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vector(vector<T>& vec) {
    cout << "print_vector -> ";
    for(int i=0; i<vec.size(); i++) {
        if(i == vec.size()-1) {
            cout << vec[i] << endl;
        }
        else {
            cout << vec[i] << " ";
        }
    }
    return;
}

int main() {

    unsigned long long A;
    long double B;

    cin >> A >> B;

    unsigned long long B100 = B * 100 + 0.5;
    unsigned long long ans = (A * B100) / 100;
    cout << ans << endl;

    return 0;
}