#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for(int i=0; i<N-2; ++i){
        if(S[i]=='A'&&S[i+1]=='B'&&S[i+2]=='C') ans++;
    }
    cout << ans << endl;
    return 0;
}
