#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;
const ll MOD=1e9+7;

ll gcd(ll x,ll y){
    if(y==0) return 0;
    return gcd(y,x%y);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    int x;cin>>x;
    int c=0;
    int n=x%100;
    for(int i=5;i>=1;i--){
        c+=n/i;
        n%=i;
    }
    if(x/100>=c){
        cout<<1<<endl;
    }else cout<<0<<endl;
    return 0;
}