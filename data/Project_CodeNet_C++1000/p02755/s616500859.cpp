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
    int a,b;
    cin>>a>>b;
    repi(i,1,1500){
        if(i*8/100==a&&i*10/100==b){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}