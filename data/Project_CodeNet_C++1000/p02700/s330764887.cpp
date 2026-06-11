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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    while(1){
        c-=b;
        if(c<=0){
            cout<<"Yes"<<endl;
            return 0;
        }
        a-=d;
        if(a<=0){
            cout<<"No"<<endl;
            return 0;
        }
    }
}