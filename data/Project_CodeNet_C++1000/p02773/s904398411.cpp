#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n;
    cin>>n;
    map<string,int> memo;
    rep(i,n){
        string s;
        cin>>s;
        memo[s]++;
    }
    int maxv=0;
    for(auto x:memo) maxv=max(maxv,x.second);
    for(auto x:memo){
        if(x.second!=maxv) continue;
        cout<<x.first<<endl;
    }
}