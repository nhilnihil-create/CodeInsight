#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    int ans = 0;
    int min = 10010010;
    rep(i, n){
        if(p[i] > min){
            continue;
        }else{
            ans++;
        }
        if(min > p[i]){
            min = p[i];
        }
    } 
    cout << ans << endl;
    return 0;
}