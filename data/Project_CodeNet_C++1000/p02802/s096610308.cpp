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
    int n,m,acnum=0,wanum=0;
    cin>>n>>m;
    bool ac[100010];
    int wa[100010];
    repi(i,1,n+1){
        ac[i]=false;
        wa[i]=0;
    }
    for(int i=0;i<m;i++){
        int p;
        string s;
        cin>>p>>s;
        if(ac[p]) continue;
        if(s=="AC"){
            ac[p]=true;
            acnum++;
            wanum+=wa[p];
        }
        else if(s=="WA") wa[p]++;
    }
    cout<<acnum<<" "<<wanum;
}