#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int h, n;
    cin >> h >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }

    if(h - sum > 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    
   return 0;
}