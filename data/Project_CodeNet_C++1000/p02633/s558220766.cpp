#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=1;
    int m=n;
    while(1){
        if(m%360==0){
            cout<<ans<<endl;
            return 0;
        }
        ans++;
        m+=n;
        m%=360;
    }
}
