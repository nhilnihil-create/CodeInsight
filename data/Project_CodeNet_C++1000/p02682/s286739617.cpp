#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int ans=0;
    if(K <= A) ans=K;
    else if(K <= A+B) ans=A;
    else if(K <= A+B+C) ans=A-(K-A-B);

    cout << ans << endl;

    return 0;
}