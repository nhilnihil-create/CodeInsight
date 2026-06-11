#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;

int main() {
    int N,K;
    cin>>N>>K;
    vi S(N+1);
    S[0]=0;
    for (int i = 1; i < N+1; i++){
        int A; cin>>A;
        S[i]=(S[i-1]+A)%K;
    }
    for (int i = 0; i < N+1; i++){
        S[i]=(i-S[i]+K)%K;
    }
    map<int,int> num;
    for (int i = 0; i < min(K,N+1); i++){
        num[S[i]]++;
    }
    ll ans=0;
    for (int i = 0; i < N+1; i++){
        ans+=num[S[i]]-1;
        num[S[i]]--;
        if(i+K<=N)num[S[i+K]]++;
    }
    cout<<ans<<endl;
}