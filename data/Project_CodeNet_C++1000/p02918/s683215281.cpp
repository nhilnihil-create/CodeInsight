#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n,k;
    cin >> n>> k;
    string s;
    cin >> s;
    
    int ka;
    ka=0;
    rep(i,n-1){
        if(s[i]!=s[i+1]){
            ++ka;
        }
    }
    int ans;
    ans=n-1-ka;

    if(k*2<=ka){
        ans+=2*k;
    }
    else{
        ans=n-1;
    }
    cout << ans << endl;
    

    return 0;
}