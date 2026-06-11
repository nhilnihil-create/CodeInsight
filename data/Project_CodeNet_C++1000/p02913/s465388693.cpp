#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define F first
#define S second

const int MOD = 1e9+7; //998244353;
inline int add(int a, int b){ return (a+b)%MOD; }
inline int sub(int a, int b){ return ((a-b)%MOD + MOD)%MOD; }
inline int mul(int a, int b){ return ((ll)a*b)%MOD; }

const int sz = 5e3+5;
int n, pwr[sz/2];
string s;

int getHash(int start, int end){
    int ans = 0;
    for(int i = start; i <= end; ++i){
        ans = add(mul(ans, 26), s[i]-'a');
    }
    return ans;
}

int roll(int hash, int newpos, int len){
    int oldpos = newpos-len;
    return add(mul(sub(hash, mul(pwr[len-1], s[oldpos]-'a')), 26), s[newpos]-'a');
}

bool works(int len){
    int hfrontst = getHash(0, len-1), hbackst = getHash(len-1, 2*len-2);
    for(int gap = 0; gap <= n-len*2; ++gap){
        hbackst = roll(hbackst, 2*len+gap-1, len);
        int hfront = hfrontst;
        int hback = hbackst;
        if(hfront == hback){
            if(s.substr(0, len) == s.substr(len+gap, len)){
                return true;
            }
        }
        for(int i = 2*len+gap; i < n; ++i){
            hfront = roll(hfront, i-len-gap, len);
            hback = roll(hback, i, len);

            if(hfront == hback){
                int frontstart = i-2*len+1-gap, backstart = i-len+1;
                if(s.substr(frontstart, len) == s.substr(backstart, len)){
                    return true;
                }
            }
        }
    }

    return false;
}

void solve(){
    cin >> n >> s;

    pwr[0] = 1;
    for(int i = 1; i <= n/2; ++i) pwr[i] = mul(pwr[i-1], 26);

    int lo = 1;
    int hi = n/2;
    int ans = 0;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(works(mid)){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}