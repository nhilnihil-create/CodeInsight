#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
#define REP(i,n) for (int i = 1; i<= (n); i++)
using ll = long long;
using namespace std;

int main() {
    double n,d;
    cin>>n>>d;
    double ans = ceil(n/(2*d+1));
    cout<<ans<<endl;
    return 0;
}