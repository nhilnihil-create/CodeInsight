#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int A, B;
    cin>>A>>B;

    int ans=-1;
    rep(i, 1001){
        if(i==0) continue;
        if(floor(i*(0.08))==A && floor(i*(0.1))==B){
            ans=i;
            break;
        }
    }

    cout<<ans<<endl;
    return 0;
}