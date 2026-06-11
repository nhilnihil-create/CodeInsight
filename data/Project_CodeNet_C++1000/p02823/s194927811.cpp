#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    long long  N,A,B; cin >> N >> A >> B;
    long long  ans;
    if((B-A)%2 == 0) ans = (B-A)/2;
    else{
        if((A+B < N+1)) ans = (A+B-1) /2;
        else ans = (2*N-A-B+1) / 2;
    }
    cout << ans << endl;
}


