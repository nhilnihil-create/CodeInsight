#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int n;
    cin >> n;
    vector<int> a(n),a2(n);
    rep(i,n) cin >> a[i],a2[i]=a[i];

    ::sort(a2.rbegin(),a2.rend());
    int first_max = a2[0];
    int second_max = a2[1];
    rep(i,n){
        if(a[i] == first_max){
            cout << second_max <<endl;
        }else{
            cout <<first_max <<endl;
        }
    }
}