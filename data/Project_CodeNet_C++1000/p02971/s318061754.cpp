#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) b[i] = a[i];
    sort(ALL(b));
    int m = b[n-1];
    rep(i,n){
        if(a[i] == m){
            cout << b[n-2] << endl;
        }
        else{
            cout << m << endl;
        }
    }


    return 0;
}