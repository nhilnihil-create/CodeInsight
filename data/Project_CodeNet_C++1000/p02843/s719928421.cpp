#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
string x;
cin>>x;
int _x=0;

if(x.size()>=3){
    //下2桁を取得
    int under_2digit=stoi(x.substr(x.size()-2,2));
    int div=5;
    map<int,int> div_num;
    while(under_2digit>0){
        div_num[div]=under_2digit/div;
        under_2digit%=div;
        div--;
    }
    for(auto v:div_num){
        _x+=(100+v.first)*v.second;
    }
}
else{
    _x=100;
}
if(_x<=stoi(x))cout<<1<<endl;
else cout<<0<<endl;
return 0;
}