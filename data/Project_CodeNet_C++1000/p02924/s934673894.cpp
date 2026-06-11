#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n;
    while(cin >> n){
        n--;
        cout << (int)(n*(n+1LL))/2LL << "\n";
    }
    return 0;
}