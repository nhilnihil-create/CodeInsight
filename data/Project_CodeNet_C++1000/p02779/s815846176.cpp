#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    set<int> s;
    int n;
    cin >> n;
    int a;
    cin >> a;
    s.insert(a);
    rep(i,n-1){
        cin >> a;
        if(s.find(a) != s.end()){
            cout<< "NO"<<endl;
            return 0;
        }
        s.insert(a);
    }

    cout<<"YES"<<endl;
}