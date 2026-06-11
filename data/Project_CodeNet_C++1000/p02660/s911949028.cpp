#include<bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

using ll = long long;
const int N = 1e6+5;

vector<int> p;
bool vis[N];
void prime() {
    p.push_back(2);
    for(int i = 3; i < N; i += 2) {
        if(!vis[i]) {
            p.push_back(i);
            for(int j = i; j < N; j += i)
                vis[j] = true;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);

    prime();

    ll n;
    cin >> n;

    map<ll,int> primeFact;
    for(int i = 0; i < p.size(); ++i) {
        if(p[i] > n) break;
      
        if(n%p[i] == 0) {
            int cnt = 0;
            while(n%p[i] == 0) {
                ++cnt;
                n /= p[i];
            }
            primeFact[p[i]] = cnt;
        }
    }
    if(n > 1) primeFact[n]++;

    vector<ll> sum(N);
    for(int i = 1; i < N; ++i)
        sum[i] += (sum[i-1] + i);

    int ans = 0;
    for(auto it : primeFact) {
        int idx = lower_bound(sum.begin(),sum.end(), it.second+1) - sum.begin();
        --idx;
        ans += idx;
    }
    cout << ans;
    return 0;
}
