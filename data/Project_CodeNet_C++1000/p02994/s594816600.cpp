#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n; ++i)


int main(){
    int n,l; cin >> n >> l;
    vector<int> c(n);
    rep(i,n){
        c[i] = l+i;
    }
    vector<int> a(n);
    a = c;
    rep(i,n){
        a[i] = abs(a[i]);
    }

    int num;

    int b;
    rep(i,n){
        if(i==0){
            b = a[i];
            num = i;
        }else{
            if(b > a[i]){
                b = a[i];
                num = i;
            }
        }
    }
    int sum=0;
    rep(i,n){
        if(i!=num){
            sum+=c[i];
        }
    }
    cout << sum << endl;


}