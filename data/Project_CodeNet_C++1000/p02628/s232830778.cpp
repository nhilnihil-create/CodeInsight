#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)
int main(){
    int n,k,sum;
    sum = 0;
    cin >> n >> k;
    vector<int> p;
    vector<int> pp;
    rep(i,n){
        int x;
        cin >> x;
        p.push_back(x);
    }
    sort(p.begin(), p.end());
    rep(j,k){
        sum += p[j];
    }
    cout << sum << endl;
}