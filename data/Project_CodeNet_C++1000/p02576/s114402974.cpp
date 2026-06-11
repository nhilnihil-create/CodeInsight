#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 77;

int main(){
    int n , x , t ; cin >> n >> x >> t ;
    if(n%x==0) cout << n/x * t << endl;
    else cout << (n/x + 1) *t << endl;
    return 0;
}