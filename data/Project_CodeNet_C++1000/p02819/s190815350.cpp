#include <bits/stdc++.h>
using namespace std;
const int n = 1000000;
int main(){
    int x; cin >> x;
    vector<int> a(n, 1);
    a[0] = 0; a[1] = 0;
    for(int i=0; i<n; ++i){
        if(a[i]!=1){continue;}
        for(int j=2*i; j<n; j+=i){
            a[j] = 0;
        }
    }
    for(int i=x; i<n; ++i){
        if(a[i]==1){cout << i << endl; return 0;}
    }
    return 0;
}