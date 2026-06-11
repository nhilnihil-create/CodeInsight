#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int N;cin>>N;
    string S;cin>>S;
    int ans=0;
    for (int i = 0; i < N-2; i++){
        if(S.substr(i,3)=="ABC")ans++;
    }
    cout<<ans<<endl;
}