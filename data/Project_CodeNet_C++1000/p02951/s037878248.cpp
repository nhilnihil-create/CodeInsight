#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int a,b,c,ans;
    cin >> a >> b >> c;
    ans=c-(a-b);
    ans=max(0,ans);
    cout << ans << endl;

    return 0;
}