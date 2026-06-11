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
    int x;
    cin>>x;
    if(x==2){
        cout<<2;
        return 0;
    }
    rep(i,x){
        int cnt=0,k=x+i;
        repi(j,2,sqrt(k)){
            if(k%j==0) cnt++;
        }
        if(cnt==0){
            cout<<x+i;
            return 0;
        }
    }
}