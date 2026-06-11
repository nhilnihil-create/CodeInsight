#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        cin >> b[i];
    }
    rep(i,n-1){
        cin >> c[i];
    }
    int get = 0;
    rep(i,n){
        get += b[a[i]-1];
        if(a[i-1]+1 == a[i])
            get += c[a[i - 1] - 1];
    }
    cout << get << endl;

    return 0;
}