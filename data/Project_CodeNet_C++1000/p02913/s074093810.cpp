#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
bool OK(int m) {
    map<string,int> d;
    for(int i=1;i<=n+1-m;i++) {
        string str=s.substr(i-1,m);
        if(d.count(str)) {
            if(i-d[str]>=m) return true;
        } else
            d[str]=i;
    }
    return false;
}
int main() {
    cin>>n>>s;
    int l=0,r=n/2;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(OK(mid))
            l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}