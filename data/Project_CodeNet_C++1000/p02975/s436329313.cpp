#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    
    int tot=0;
    rep(i,n) tot = tot ^ a.at(i);
    if(tot == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}