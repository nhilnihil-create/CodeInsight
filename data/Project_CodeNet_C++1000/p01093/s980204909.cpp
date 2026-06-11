#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int a[1001];
int main(){
    int n;
    while(cin>>n,n){
        rep(i,n) cin>>a[i];
        sort(a,a+n);
        int mn=1000100010;
        FOR(i,1,n){
            mn=min(mn,a[i]-a[i-1]);
        }
        cout<<mn<<endl;
    }
    return 0;
}
