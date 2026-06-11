#include <bits/stdc++.h>
using namespace std;
const int N = (int) 1e5+5;

int n;
void ngk(){
    cin >> n;
    
    if (n < 3 || __builtin_popcount(n) == 1) {
        cout << "No";
        return;
    }
    else {
        cout << "Yes" << '\n';
        cout << 2 << ' ' << 3 << '\n';
        cout << 3 << ' ' << 1 << '\n';
        cout << 1 << ' ' << n+2 << '\n';
        cout << n+2 << ' ' << n+3 << '\n';
        cout << n+3 << ' ' << n+1 << '\n';
        for(int i=4;i<n;i+=2){
            cout << i << ' ' << i+1 << '\n';
            cout << i+1 << ' ' << 1 << '\n';
            cout << 1 << ' ' << i+n << '\n';
            cout << i+n << ' ' << i+n+1 << '\n';
        }
        if (n % 2 == 0){
            int large_bit = (1<<(31 - __builtin_clz(n)));
            cout << n << ' ' << large_bit+n << '\n';
            cout << n+n << ' ' << (n^1^large_bit) << '\n';
        }
    }
    
} 

int main(){
    #ifdef NGKCP
        freopen("input.txt","r",stdin);
    #endif
    iostream::sync_with_stdio(0);
    ngk();
}
/*
    Array limits;
    Corner cases;
*/