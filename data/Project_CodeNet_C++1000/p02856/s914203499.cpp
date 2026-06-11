#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define ll long long
using namespace std;
int main(){
    int n; cin>>n; ll s1=0,s2=0;
    rep(i,1,n){
        int d; ll c; scanf("%d%lld",&d,&c);
        s1+=c,s2+=d*c;
    }
    cout<<s1-1+(s2-1)/9<<endl;
    return 0;
}
