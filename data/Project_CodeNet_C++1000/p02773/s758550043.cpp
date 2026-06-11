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
    map<string,int> memo;
    int n;
    cin>>n;
    string s;
    rep(i,n){
        cin>>s;
        memo[s]++;
    }
    int maxi=0;
    for(auto x:memo){
        int v=x.second;
        if(v>maxi) maxi=v;
    }
    for(auto y=memo.begin();y!=memo.end();y++){
        if(y->second==maxi) cout<<y->first<<endl;
    }
}