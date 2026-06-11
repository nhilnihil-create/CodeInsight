#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n); 
    vector<int> b(n);
    int m = 0, mm = 0; 
    queue<int> mi;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end(), greater<int>());
    int f, s; 
    f = b[0]; s = b[1];
    for(int i=0; i<n; ++i){
        if(a[i]==f){cout << s << endl;}
        else{cout << f << endl;}
    }
    return 0;
}