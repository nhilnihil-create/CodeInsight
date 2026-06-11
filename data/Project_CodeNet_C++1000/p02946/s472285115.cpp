#include <bits/stdc++.h>
using namespace std;

int main(){
    int K, X;
    cin >> K >> X;
    vector<int> A(2*K-1);
    int p = X - (K-1);
    for(int i=0; i<2*K-1; i++){
        A.at(i) = p;
        cout << p << " ";
        p++;
    }
    cout << endl;
}