#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    string s;
    cin>>s;
    int ans=0;
    string t[7]={"SAT","FRI","THU","WED","TUE","MON","SUN"};
    rep(i,7){
        if(s==t[i]){
            ans=i+1;
        }
    }
    cout << ans<<endl;
}