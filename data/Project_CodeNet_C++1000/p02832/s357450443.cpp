#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    int ans=0;
    bool one=true;
    int count=0;
    rep(i,n){
        cin>>a[i];
        if(a[i]==1 && one){
            ans+=i;
            count=i;
            one=false;
        }else if(a[count]+1==a[i] && !(one)){
            ans=ans+i-count-1;
            count=i;
        }
    }
    if(one) cout<<-1<<endl;
    else cout<<ans+n-1-count<<endl;
}