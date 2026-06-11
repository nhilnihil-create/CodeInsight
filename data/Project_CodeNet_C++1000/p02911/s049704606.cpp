#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl 
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> a(n);
    rep(i,q){
        int l;
        cin >> l;
        l--;
        a[l]++;
    }
    rep(i,n){
        if(k-q+a[i] <= 0) cno;
        else cyes;
    }
    return 0;
}