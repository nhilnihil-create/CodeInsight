#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
using ll = long long;
using namespace std;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    int n;
    string s,t;
    cin>>n>>s>>t;
    int j=0;
    rep(i,2*n){
        if(i%2==0)
            cout<<s[j];
        if(i%2==1)
            cout<<t[j++];
    }
}