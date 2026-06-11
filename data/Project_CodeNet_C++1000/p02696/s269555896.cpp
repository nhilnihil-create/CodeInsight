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

    unsigned long long A, B, N;
    cin >> A >> B >> N;

    unsigned long long x;
    if(B-1>N) x = N;
    else x = B-1;

    cout << (A * x) / B - A * (x / B) << endl;
    
    return 0;
}