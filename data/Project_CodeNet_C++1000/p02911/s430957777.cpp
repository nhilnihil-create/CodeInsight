#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll k;
    int q;
    cin >> n >> k >> q; 
    int a;
    vector<int> table(n,0);
    rep(i,q){
        cin >> a;
        a--;
        table[a]++;
    }

    rep(i,n){
        if(table[i] > q-k) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;

}