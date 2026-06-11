#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int n,k,c;
string s;
int l[200001],r[200001];
int main(){
    cin>>n>>k>>c>>s;
    int pre=-1000000,cnt=0;
    rep(i,n){
        if(s[i]=='o'&&pre+c<i){
            l[cnt]=i;pre=i;
            ++cnt;
            if(cnt>=k) break;
        }
    }
    pre=1000000,cnt=0;
    for(int i=n-1;i>=0;--i){
        if(s[i]=='o'&&pre-c>i){
            r[k-cnt-1]=i;pre=i;
            ++cnt;
            if(cnt>=k) break;
        }
    }
    rep(i,k)if(r[i]==l[i])cout<<r[i]+1<<endl;
    return 0;
}