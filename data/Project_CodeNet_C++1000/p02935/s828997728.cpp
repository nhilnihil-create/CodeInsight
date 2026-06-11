#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int n;cin>>n;
    priority_queue<double> v;
    rep(i,n){
        int a;cin>>a;
        v.push(-a);
    }
    double sum=0;
    for(int i=0;i<n-1;i++){
        double a=v.top();
        v.pop();
        double b=v.top();
        v.pop();
        v.push((a+b)/2.0);
    }

    cout <<-v.top();

    
}