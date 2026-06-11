#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int a[1000001];
vector<int> v;
int cnt;
void insertsort(int n,int g){
    FOR(i,g,n){
        int ai=a[i];
        int j=i-g;
        while(j>=0&&a[j]>ai){
            a[j+g]=a[j];
            j=j-g;
            ++cnt;
        }
        a[j+g]=ai;
    }
}
int main(){
    int n;
    cin>>n;
    rep(i,n) cin>>a[i];
    int p=1;
    while(p<=n){
        v.pb(p);
        p*=2;
    }
    cnt=0;
    reverse(v.begin(),v.end());
    for(auto it:v) insertsort(n,it);
    cout<<v.size()<<endl;
    rep(i,v.size()) cout<<v[i]<<(i==v.size()?"":" ");
    cout<<endl;
    cout<<cnt<<endl;
    rep(i,n) cout<<a[i]<<endl;
    return 0;
}
