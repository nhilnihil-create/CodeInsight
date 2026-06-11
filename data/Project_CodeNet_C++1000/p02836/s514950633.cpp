#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin>>s;
    int cnt=0;
    rep(i,s.size()/2){
        if(s[i]!=s[s.size()-1-i])cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}
