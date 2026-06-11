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
//整数の割り算の切り上げ
int64_t updiv(int64_t a,int64_t b){
    return (a+(b-1))/b;
}
int main(){
    int64_t n,k;
    cin>>n>>k;
    vector<int64_t> a(n);
    int64_t amax=0;
    rep(i,n){
        cin>>a[i];
        amax = max(amax,a[i]);
    }
    int ans;
    int r = amax,l=1;
    int m;
    while(r-l>1){
        m=(r+l)/2;
        int fl=0;
        rep(i,n){
            fl += updiv(a[i],m)-1;
        }
        if(fl<=k) {//もっと切れる
            r = m;
        }
        else{//fl>k ->そんなに切れない->
            l = m;
        }
    }
    //lとrを比較
    int last=0;
    rep(i,n){
        last += updiv(a[i],l)-1;
    }
    if(last>k){
        cout<<r<<endl;
    }
    else{
        cout<<l<<endl;
    }
}