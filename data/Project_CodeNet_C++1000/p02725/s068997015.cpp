#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main(){
    int k,n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i, n){
        cin >> a.at(i);
    }
    int maxa = 0;
    rep(i, n-1){
        int tmp = a.at(i+1) - a.at(i);
        if(tmp>maxa) maxa = tmp;
    }
    if(a.at(0)+k-a.at(n-1) > maxa) maxa = a.at(0)+k-a.at(n-1);
    cout << k-maxa << endl;
    return 0;
}