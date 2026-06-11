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
    int a,b,k;
    cin>>k>>a>>b;
    for(int i=a;i<=b;i++){
        if(i%k==0){
            cout<<"OK";
            return 0;
        }
    }
    cout<<"NG";
}