#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=1; i<(n+1)/2; ++i){
        if(i!=n-i)ans++;
    }
    cout<<ans<<endl;
    return 0;
}