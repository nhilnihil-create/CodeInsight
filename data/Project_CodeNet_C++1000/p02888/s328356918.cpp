#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;

int main() {
    int N; cin>>N;
    vi L(N);
    for (int i = 0; i < N; i++){
        cin>>L[i];
    }
    int ans=0;
    sort(L.begin(),L.end());
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            int kl=upper_bound(L.begin(),L.end(),L[j]-L[i])-L.begin();
            int kr=lower_bound(L.begin(),L.end(),L[i]+L[j])-L.begin()-1;
            if(kr>j)ans+=kr-max(kl,j+1)+1;
        }
    }
    cout<<ans<<endl;
}