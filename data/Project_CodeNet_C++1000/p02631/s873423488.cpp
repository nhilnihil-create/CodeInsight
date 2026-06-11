#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    long long a=0;
    cin >> num;

    vector<long long> vec(num);
    for (long long i = 0; i < num; i++){
        cin >> vec.at(i);
        a = a ^ vec.at(i);
    }

    for (long long i = 0; i < num; i++){
        cout << (a ^ vec.at(i)) << " ";
    }

    //
}
