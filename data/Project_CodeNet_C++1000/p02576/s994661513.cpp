#include <bits/stdc++.h>
using namespace std;

#define print cout <<

int main(){
    int N, X, T;
    cin >> N >> X >> T;
    int times = (N + X -1) / X;

    print T * times << endl;
}
