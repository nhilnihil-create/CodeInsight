#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define oo 100000000000000000
using namespace std;


string s,t;

int get(int id){
    int cnt = 0 , sz = t.size() - 1 ;
    for(int i=1;i<=sz;i++) cnt += ( s[id - sz + i ] != t[ i ] );
    return cnt;
}

void _sol(){
    cin >> s >> t;
    int n = s.size();
    int k = t.size();
    s = '$' + s;
    t = '$' + t;
    int ans = INT_MAX;
    for(int i=k;i<=n;i++){
        ans  = min(ans , get(i));
    }
    cout << ans;

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    _sol();
}
