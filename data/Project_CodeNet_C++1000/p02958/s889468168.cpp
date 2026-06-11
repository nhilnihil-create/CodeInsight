#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)

int main(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    vector <int> a(n);
    rep(i,n) a[i] = i+1;
    int num=0;
    rep(i,n) {
        if(p[i] != a[i]){
            ++num;
        }
    }
    if(num == 2 || num == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}