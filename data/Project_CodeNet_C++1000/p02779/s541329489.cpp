#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string YES = "YES";
const string NO = "NO";

void solve(long long N, std::vector<long long> A){
    map<ll, ll> mp;
    string ans = YES;
    for(auto a : A) mp[a]++;
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        if(itr->second > 1){
            ans = NO;
            break;
        }
    }
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
