#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
typedef signed long long ll;
#define FOR(i,to) for(i=0;i<(to);i++)

int64_t n; 
bool dp[1000000+10];
ll  cnt[1000000+10];


int main() {
	int i,j,k,l,r,x,y; string s;
    
    ll N;
    cin >> N;
    ll A[N];

    
    
    FOR(i,N){ 
        cin >> A[i]; 
        dp[A[i]]=true;
        cnt[A[i]]++;
    }

    for(i=1000000; i>=1; i--){
        for(j=2*i; j<=1000000; j+=i){
            if(dp[j]&&dp[i]) dp[j]=false;
        }
    }

    sort(A, A+N);
    ll ans=0; 

    FOR(i,N){
        if(cnt[A[i]]==1){
            if(dp[A[i]]){
                ans++; 
            }
        }
    }

    std::cout << ans;
    return 0;
}
