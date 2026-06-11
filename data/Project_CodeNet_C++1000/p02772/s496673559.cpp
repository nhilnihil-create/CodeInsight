#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    bool ans = true;
    for(int i = 0; i < n; i++){
        if(a[i]%2 == 0 && a[i]%3 != 0 && a[i]%5 != 0){
           ans = false;
           break;
        }
    }

    if(ans) cout << "APPROVED" << endl;
    else cout << "DENIED" << endl;

   return 0;
}