#include <bits/stdc++.h>
using namespace std;

long combi(int n, int r) {
    if (r == 0) {
        return 1;
    }
    
    return (n - r + 1) * combi(n, r - 1) / r;
}

int main(void){
    
    int N,M;
    cin >> N >> M;
    cout << combi(N,2) + combi(M,2) << endl;    
}