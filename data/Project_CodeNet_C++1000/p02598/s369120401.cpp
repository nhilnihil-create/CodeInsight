//
//  main.cpp
//  ABC174E
#include <iostream>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
vector<int>a;
int n,k;
bool cc(int m){
    ll now=0;
    rep(i,n) now+=((a.at(i)-1)/m); // 答えをmとした時の、それぞれの丸太を切る回数の合計
    if(now<=k){
        return true;
    }else{
    return false;
    }
}
int main(int argc, const char * argv[]) {
    cin>>n>>k;
    a.resize(n);
    rep(i,n) cin >> a.at(i);
    int l=0;
    int r=1e9;
    while(r-l > 1){
        int m=(l+r)/2;
        if(cc(m)==true){
            r=m;
        }else{
            l=m;
        }
    }
    cout<<r<<endl; // 答えは切り上げなので右側を採用する
    return 0;
}
