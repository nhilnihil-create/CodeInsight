#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    ll k;
    cin>>k;
    ll now = 7%k;
    rep(i, k){
        if(now == 0) {
            cout<<i+1<<endl;
            return 0;
        }
        now = (now*10+7)%k;
    }
    cout<<-1<<endl;
    return 0;
}