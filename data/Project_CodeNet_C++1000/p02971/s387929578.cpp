
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)

int main(){
    int n; cin >> n;
    vector <int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b = a;
    sort(a.begin(), a.end());
    int max_1 = a[n-1];
    int max_2 = a[n-2];
    rep(i,n){
        if(b[i] == max_1){
            cout << max_2 << endl;
        }else{
            cout << max_1 << endl;
        }
    }
}
