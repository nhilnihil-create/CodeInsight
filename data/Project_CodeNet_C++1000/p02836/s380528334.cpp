#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<int(n); i++)
int main() {
    string S;
    cin>>S;
    int ans=0;
    int a=S.size();
    for(int i=0; i<a/2; i++){
        if(S.at(i)!=S.at(a-1-i)){
            ans++;
        }
    }
    cout<<ans<<endl;
}

