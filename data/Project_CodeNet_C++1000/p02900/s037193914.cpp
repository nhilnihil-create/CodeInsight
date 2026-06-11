#include<bits/stdc++.h>
using namespace std;

#define     int long long
#define     pii pair<int,int>
#define     x first
#define     y second
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define     MOD 1000000007
#define     INF 100000000
#define     nll cout << "\n"
#define     nl "\n"
#define     MAX 1000003
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     vl vector<ll>
#define     pb push_back
#define     con continue

int xx[] = {1, -1, 0, 0};
int yy[] = {0, 0, -1, 1};

vector<int>prime;
bitset<1000005>isPrime;

void seive(){
    isPrime.set();
    for(int i = 2; i < MAX; i++){
        if(isPrime[i]){
            prime.pb(i);
            for(int j = i*2; j < MAX; j+=i)isPrime[j] = false;
        }
    }
}

bool utilFun(int n){
    for(int i = 0; prime[i] <= sqrt(n); i++){
        if(n%prime[i] == 0){
            return false;
        }
    }
    return true;
}

int32_t main(){
    seive();
    int n, m;
    while(cin >> n >> m){
        map<int, bool>mp;
        for(int i = 0; prime[i] <= sqrt(n); i++){
            int pf = prime[i];
            if(n%pf == 0){
                mp[pf] = true;
                while(n%pf == 0)n /= pf;
            }
        }
        if(n > 1){
            mp[n] = true;
        }
        int cnt = 1;
        for(int i = 0; prime[i] <= sqrt(m); i++){
            int pf = prime[i];
            if(m%pf == 0){
                if(mp[pf] == true)cnt++;
                while(m%pf == 0)m/=pf;
            }
        }
        if(m > 1){
            if(mp[m])cnt++;
        }
        asdf(cnt);
    }
}
