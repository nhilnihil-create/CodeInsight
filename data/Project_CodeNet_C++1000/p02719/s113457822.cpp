#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
    vector<int>c(10);

    long long N,K;
    cin >> N >> K;
    if(N % K == 0){
        cout << 0 << endl;
        return 0;
    }
    long long rest = N % K;
    cout << min(rest,abs(rest - K));
}
