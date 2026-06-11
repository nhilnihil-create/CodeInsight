//
//  main.cpp
//  ABC136D
#include <iostream>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
int main(int argc, const char * argv[]) {
    string s;
    cin>>s;
    ll n=s.size();
    vector<int>ans(n);
    rep(i,2){
        int cnt=0;
        rep(j,n){
            if(s[j]=='R') cnt++;
            else {
                ans[j]+=cnt/2;
                ans[j-1]+=(cnt+1)/2;
                cnt=0;
            }
        }
    reverse(ans.begin(), ans.end());
    reverse(s.begin(), s.end());
    rep(i,n){
        if(s[i]=='L') s[i]='R';
        else s[i]='L';
    }
}
    rep(i,n-1) cout<<ans.at(i)<<" ";
    cout<<ans.at(n-1)<<endl;
    return 0;
}
