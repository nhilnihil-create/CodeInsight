#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin>>n>>s;
    bool flag=true;
    if(n%2==1)flag=false;
    else{
        rep(i,n/2){
            if(s[i]!=s[n/2+i])flag=false;
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
