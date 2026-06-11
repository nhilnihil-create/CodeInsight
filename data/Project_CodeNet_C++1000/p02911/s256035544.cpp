#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> p(n, k) ;
    int a;
    rep(i, q){
        cin >> a;
        p[a - 1] += 1;
    } 
    rep(i, n){
        p[i] -= q;
        if(p[i] > 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }    
    return 0;
}