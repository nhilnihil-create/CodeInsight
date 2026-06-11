#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<int> p(n);
    int count=0;
    rep(i,n){
        cin>>p[i];
        if(p[i]!=i+1) count++;
    }
    if(count==2 || count==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
