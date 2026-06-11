#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i) 

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    rep(i,n) cin >> a[i];
    int num=0;
    rep(i,n){
        if(i == 0 || i == n-1){
            continue;
        }else{
            if(a[i-1] < a[i] && a[i+1] > a[i]){
                ++num;
            }
            if(a[i-1] > a[i] && a[i+1] < a[i]){
                ++num;
            }
        }
    }
    cout << num << endl;
}