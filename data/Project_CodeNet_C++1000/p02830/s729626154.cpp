#include<bits/stdc++.h>
using namespace std;

int n;
string s,t,ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s>>t;
    for(int i=0;i<n;i++){//从前往后跑s和t的字符
        ans+=s[i];
        ans+=t[i];//向ans的末尾添加字符
    }
    cout<<ans<<endl;

    return 0;
}