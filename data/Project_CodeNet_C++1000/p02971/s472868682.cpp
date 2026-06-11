#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    rep(i, n){
        cin >> a[i];
        p[i] = a[i];
    }
    sort(p.begin(), p.end());
    int max1 = p[n - 1];
    int max2 = p[n - 2];
    rep(i,n){
        if(a[i] != max1){
            cout << max1 << endl;   
        }else{
            cout << max2 << endl;  
        }        
    }
    return 0;
}