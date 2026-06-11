#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "E:\CP\Debugger\debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 
const int MX = 1e6+5;
#define pii pair<int, int>

vector<int> nth_prime;
bitset<MX> visited; 
void optimized_prime(){
    nth_prime.push_back(2);
    for(int i=3; i<MX; i+=2){
            if(visited[i]) 
                continue;
            nth_prime.push_back(i);
            if(1ll*i*i > MX) 
                continue;
            for(int j = i*i; j< MX; j+= i+i)
                visited[j] = true;
    }
}
signed main(){
    optimized_prime();
    int n; cin>>n;
    for(int i=0; i<nth_prime.size(); ++i){
        if(nth_prime[i] >= n){
            cout<<nth_prime[i]<<"\n";
            return 0;
        }
    }
}