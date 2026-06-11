
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    string s;
    cin >> s;
    int ans=0;
    int n=s.size();
    //偶数
    if(n%2==0){
        rep(i,n/2){
            if(s[i]!=s[n-1-i]) ans++;
        }
    }
    //奇数
    else{
        rep(i,n/2){
            if(s[i]!=s[n-1-i]) ans++;
        }
    }
    cout << ans << endl;
}