#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    ll n,k,q;
    cin >> n>>k>>q;
    vector<ll> points(n);
    rep(i,n){
        points[i] = k-q;
    }
    rep(i,q){
        ll answer;
        cin>>answer;
        points[answer-1]++;
    }
    rep(i,n){
        if(points[i]>0) cout << "Yes"<<endl;
        else cout<<"No"<<endl;
    }
}