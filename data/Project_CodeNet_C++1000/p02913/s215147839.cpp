#include <bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b){return(a=max(a,b))==b;}
int n, ans=0,l=0,r=1;
string s;
int main(){
    cin>>n>>s;
    for(;r<=n;r++){
        if(s.find(s.substr(l,r-l),r)<n)chmax(ans,r-l);
        else l++;
    }
    cout<<ans<<endl;
    return 0;
}
