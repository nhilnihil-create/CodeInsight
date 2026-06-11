#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 1; i < n; i++){
        cin >> b[i];
        a[b[i] - 1] += 1;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    
    return 0;
}