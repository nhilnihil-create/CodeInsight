#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin>>N;
    string S;cin>>S;
    char prev=S[0];
    int ans=1;
    for (int i = 1; i < N; i++){
        if(S[i]!=prev)ans++;
        prev=S[i];
    }
    cout<<ans<<endl;
}