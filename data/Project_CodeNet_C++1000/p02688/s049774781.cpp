#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n, k, d, a;
    cin>>n >>k;
    vector<int> num(n);
    int ans=n;
    rep(i,k){
        cin>>d;
        rep(m,d){
            cin>>a;
            if(num.at(a-1)==0){
                ans--;
                num.at(a-1)++;
            }
        }
    }
    cout<<ans<<endl;
}