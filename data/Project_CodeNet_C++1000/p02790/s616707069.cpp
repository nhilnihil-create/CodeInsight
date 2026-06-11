#include <bits/stdc++.h>
using namespace std;


void solve(long long a, long long b){
    string aa = to_string(a);
    for(int i = 0; i < b-1; ++i){
        aa = aa + to_string(a);
    }
    string bb = to_string(b);
    for(int i = 0; i < a-1; ++i){
        bb = bb + to_string(b);
    }
    cout << min(aa, bb) << endl;
}

int main(){
    long long a;
    scanf("%lld",&a);
    long long b;
    scanf("%lld",&b);
    solve(a, b);
    return 0;
}
