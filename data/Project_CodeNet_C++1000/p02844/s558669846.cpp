#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;
int A[N];
int32_t main(){
    fast;
    int n ; cin >> n ;
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < 1000 ; ++i){
        int a = i/100 , b = (i/10)%10 , c = i%10;
        int C[3] = {a,b,c};
        int idx = 0;
        for(int j = 0 ; j < n ; ++j){
            if(s[j]==(C[idx] +'0')) idx++;
            if(idx==3) break;
        }
        if(idx==3) ans++;
    }
    cout << ans << endl;
    return 0;
}