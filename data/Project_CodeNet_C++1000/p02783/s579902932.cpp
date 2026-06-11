#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int H,A; cin >> H >> A;
    int ans=0;
    while(H>0) {
        H-=A;
        ans++;
    }
    cout << ans << endl;
}