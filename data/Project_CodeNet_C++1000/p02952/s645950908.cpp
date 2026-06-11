#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int n;
    cin >> n;
    int copy=n;
    int cnt=0;
    while(copy>0){
        copy/=10;
        cnt++;
    }
    int ans=0;
    if(cnt==1){
        ans=n;
    }
    else if(cnt<3){
        ans=9;
    }
    else if(cnt==3){
        ans+=9;
        ans+=(n-99);
    }
    else if(cnt<5){
        ans+=9;
        ans+=900;
    }
    else if(cnt==5){
        ans+=9;
        ans+=900;
        ans+=(n-9999);
    }
    else {
        ans+=90909;
    }
    cout << ans << endl;
}
