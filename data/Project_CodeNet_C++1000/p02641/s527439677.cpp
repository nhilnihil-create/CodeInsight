#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    int x,n; cin >> x >> n;
    if(n==0) cout << x << endl;
    else {
        vector<int> A(102,0);
        rep(i,n) {
        int p; cin >> p;
        A[p]++;
        }
        int r=101,ans=0;
        for(int i=101; i>=0; i--) {
            if(A[i]==0) {
                int R=abs(x-i);
                if(R<=r){
                    r=R; ans=i;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}