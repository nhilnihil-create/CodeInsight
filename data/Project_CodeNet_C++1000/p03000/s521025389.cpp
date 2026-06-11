#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n,x;cin>>n>>x;
    int ans = 1;
    int t = 0;
    rep(i,n){
        int tmp;cin>>tmp;
        t+=tmp;
        if(t<=x)++ans;
        else break;
    }
    cout<<ans<<endl;
	return 0;
}