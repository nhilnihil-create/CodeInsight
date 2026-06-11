#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n; cin>>n;
    int k; cin>>k;
    string s; cin>>s;
    int cnt=1;
    rep(i,n-1){
        if(s[i]!=s[i+1]) cnt++;
    }
    cout<<min(n-1,n-cnt+2*k)<<endl;
    return 0;
}