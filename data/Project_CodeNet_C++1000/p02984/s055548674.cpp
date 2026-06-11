#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    int n;
    cin >> n;
    vector <long long> a(n);
    rep(i,n) cin >> a[i];

    vector <long long> b(n);

    for(int i=0; i<n; i++){
        b[0] += pow(-1,i%2) * a[i];
    }
    for(int i=1; i<=n-1; i++){
        b[i] = 2 * a[i-1] - b[i-1];
    }
    b[n-1] = 2 * a[n-1] - b[0];

    rep(i,n){
        if(i == n-1){
            cout << b[i] << endl;
        }
        else
        {
            cout << b[i] << " ";
        }
        
    }
}