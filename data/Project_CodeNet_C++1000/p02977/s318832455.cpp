#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    int n; cin >> n;
    int d = log2(n);
    if(n == (1 << d)){
        cout << "No" << endl;
        return 0;
    }
    else cout << "Yes" << endl;

    int r = n % 4;
    if(r == 0){
        FOR(i, 1, n-1){
            cout << i << " " << i+1 << endl;
            cout << i+n << " " << i+n+1 << endl;
        }
        cout << n-1 << " " << n+1 << endl;
        cout << n << " " << n-1 << endl;
        cout << 2*n <<  " " << ((n^(n-1))-1+n) << endl;
        return 0;
    }
    if(r == 1){
        FOR(i, 1, n-2){
            cout << i << " " << i+1 << endl;
            cout << i+n << " " << i+n+1 << endl;
        }
        cout << n-2 << " " << n+1 << endl;
        cout << n-1 << " " << n << endl;
        cout << n << " " << 1 << endl;        
        cout << 1 << " " << 2*n-1 << endl;        
        cout << 2*n-1 << " " << 2*n << endl;
        return 0;
    }
    if(r == 2){
        FOR(i, 1, n-3){
            cout << i << " " << i+1 << endl;
            cout << i+n << " " << i+n+1 << endl;
        }
        cout << n-3 << " " << n+1 << endl; 
        cout << n-1 << " " << n-2 << endl;        
        cout << n << " " << n-2 << endl;        
        cout << n-2 << " " << 2 << endl;        
        cout << 2 << " " << 2*n << endl;        
        cout << 2*n-1 << " " << 3 << endl;        
        cout << 2*n-1 << " " << 2*n-2 << endl;
        return 0;
    }
    if(r == 3){
        FOR(i, 1, n){
            cout << i << " " << i+1 << endl;
            cout << i+n << " " << i+n+1 << endl;
        }
        cout << n << " " << n+1 << endl;
        return 0;
    }
}