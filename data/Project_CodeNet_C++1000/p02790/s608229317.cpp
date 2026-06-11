#include <bits/stdc++.h>
using namespace std;

int main () {
    int a,b;
    cin >> a >> b;

    vector<int> A(b);
    for (int i = 0; i < b; i++){
        A.at(i) = a;
    }

    vector<int> B(a);
    for (int i = 0; i < a; i++){
        B.at(i) = b;
    }

    if (a < b) for (int i = 0; i < b; i++)cout << a;
    else for(int i = 0; i < a; i++)cout << b;

    cout << endl;
}