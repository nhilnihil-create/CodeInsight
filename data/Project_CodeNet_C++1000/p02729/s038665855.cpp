#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int N,M;
    cin >> N >> M;
    int ans = 0;
    int NN = 1;
    int NM = 1;
    
    NN = N*(N-1)/2;
    NM = M*(M-1)/2;
    
    ans = NN + NM;

    cout << ans << endl;
}