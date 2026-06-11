#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int p[n];rep(i,n)cin>>p[i];
    
    int ans = 1;
    int tmp = p[0];
    rep(i,n-1){
        if(p[i+1]<tmp){
            ++ans;
            tmp = p[i+1];
        }
    }
    
    cout<<ans<<endl;
	return 0;
}