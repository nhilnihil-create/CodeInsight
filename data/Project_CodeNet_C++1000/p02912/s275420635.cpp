#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int n,m;cin>>n>>m;
    priority_queue<int> value;
    rep(i,n){
        int a;cin>>a;
        value.push(a);
    }
    rep(i,m){
        int top=value.top()/2;
        value.pop();
        value.push(top);
    }
    ll sum=0;
    while(!value.empty()){
        sum+=value.top();
        value.pop();
    }
    cout <<sum;
}