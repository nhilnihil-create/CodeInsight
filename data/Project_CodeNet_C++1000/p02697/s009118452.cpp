#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int n,m;
int main(){
    cin>>n>>m;
    int cnt=0;
    int l=n-(m+1)/2*2+1,r=n;
    int p=(r-l)%2;
    while(l<r&&cnt<m){
        cout<<l<<" "<<r<<endl;
        ++l,--r;++cnt;
    }
    l=1,r=n-(m+1)/2*2;
    if((r-l)%2==p) ++l;
    while(l!=r&&cnt<m){
        cout<<l<<" "<<r<<endl;
        ++l,--r;++cnt;
    }
    return 0;
}