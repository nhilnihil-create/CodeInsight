#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define INF 1000000000
#define MAX 1000002

vector<int>prime;
bitset<MAX>bit;

void seive(){
    bit.set();
    for(int i = 2; i < MAX; i++){
        if(bit[i]){
            prime.push_back(i);
            for(int j = i*2; j < MAX; j+=i){
                bit[j] = false;
            }
        }
    }
    return;
}

int32_t main(){
    seive();
    int n;
    while(cin >> n){
        map<int, int>mp;
        for(int i = 0; i < prime.size() && prime[i] <= n; i++){
            int pf = prime[i];
            int cnt = 0;
            if(n%pf == 0){
                while(n%pf == 0){
                    cnt++;
                    n /= pf;
                }
                mp[pf] = cnt;
            }
        }
        if(n > 1){
            mp[n] = 1;
        }
        int ans = 0;
        for(auto x : mp){
            int v = x.second;
            for(int i = 1; ; i++){
                int tv = (i*(i+1))/2;
                if(tv == v){
                    ans += i; break;
                }
                if(tv > v){
                    ans += (i-1); break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}