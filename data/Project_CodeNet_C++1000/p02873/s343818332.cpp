#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>
 
#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;
 
int main(){
    string s;
    cin >> s;
    int n = s.length();
    vl a(n+1);
    rep(i,n + 1){
        if(s[i] == '<'){
            a[i+1] = max(a[i+1],a[i] + 1);
        }
    }
 
    for(int i = n;i >= 0; i--){
        if(s[i] == '>'){
            a[i] = max(a[i],a[i+1]+1);
        }
    }
    ll ans = 0;
    rep(i,n+1){
        //cout << a[i]  << " ";
        ans+= a[i];
    }
    //cout << endl;
    cout << ans << endl;
    return 0;
}