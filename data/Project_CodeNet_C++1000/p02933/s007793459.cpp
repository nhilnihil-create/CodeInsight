#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define prin(a) cout<<(a)<<endl
using ll=int64_t;
using namespace std;

//define gcd and lcm (using 64bit)
ll gcd(ll a,ll b){
    if (a < b) {
        //^はxor(bitwise operator)。以下三行でswap(a,b)を行っている。
        a ^= b;
        b ^= a;
        a ^= b;
    }
    //only when b==0,this program finds that b means false and returns a.
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a,ll b){
    return a * b / gcd(a, b);
}


int main(){
    int a;
    string s;
    cin>>a>>s;
    cout<<(a>=3200? s: "red")<<endl;
    return 0;
}