#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int N;
    cin>>N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)cin>>A[i];
    sort(A.begin(),A.end(),greater<int>());
    ll ans=-A[0];
    for (int i = 0; i < N/2; i++){
        ans+=2*A[i];
    }
    if(N%2==1)ans+=A[N/2];
    cout<<ans<<endl;
}