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

    long long x;
    cin >> x;

    for(long long A = -200; A < 200; A++) {
        for(long long B = -200; B < 200; B++) {
            long long A5 = A * A * A * A * A;
            long long B5 = B * B * B * B * B;

            if(A5 - B5 == x) {
                cout << A << " " << B << endl;
                return 0;
            } 
        }
    }

    return 0;
}