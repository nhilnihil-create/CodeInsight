#include<bits/stdc++.h>
using namespace std;
using Int = long long;

int main(){
    Int M ; cin >> M;
    vector<Int>d(M), c(M); Int sum = 0;
    for(int i = 0; i < M;++i) cin >> d[i] >> c[i], sum += d[i] * c[i];
    cout << accumulate(c.begin(),c.end(),0LL) - 1+ (sum-1)/9 << endl;
}

