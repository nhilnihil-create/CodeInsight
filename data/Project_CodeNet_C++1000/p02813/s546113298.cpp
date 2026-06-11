#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;

int main() {
    int N;cin>>N;
    vi P(N),Q(N);
    for (int i = 0; i < N; i++)cin>>P[i];
    for (int i = 0; i < N; i++)cin>>Q[i];
    if(P>Q)swap(P,Q);
    int ans=0;
    while(P<Q){
        next_permutation(P.begin(),P.end());
        ans++;
    }
    cout<<ans<<endl;
}