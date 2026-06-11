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
    bool flag=true;
    for(int i=0;i<s.size();i++){
        if(i%2==0){
            if(s[i]=='L')flag=false;
        }
        else{
            if(s[i]=='R')flag=false;
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}