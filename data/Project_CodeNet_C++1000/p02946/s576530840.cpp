#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main(){
    int k,x;
    cin >> k >> x;
    int start = x - k + 1;
    int end = x + k - 1;
    for(int i=start; i<=end; i++){
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}