#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> point(n,0);
    int a;
    for(int i=0; i<q; i++){
        cin >> a;
        point.at(a-1)++;
    }
    for(int i=0; i<n; i++){
        if(q-point.at(i)<k) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}