#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
#define ld long double
//最大公約数　最小公倍数はa*b/GCD(a,b)
int64_t GCD(int64_t a,int64_t b){
    return b == 0 ? a : GCD(b, a % b);
}
int64_t LCM(int64_t a,int64_t b){
    if(a%b==0){
        return a;
    }
    if(b%a==0){
        return b;
    }
    return a/GCD(a,b)*b;
}
int64_t count_not_div(int64_t n,int64_t a,int64_t b,int64_t c){
    return (n-(n/a+n/b-n/c));
}
int main(){
    int64_t a,b,c,d;
    cin>>a>>b>>c>>d;
    int64_t lcm = LCM(c,d);
    cout<<count_not_div(b,c,d,lcm)-count_not_div(a-1,c,d,lcm)<<endl;
}