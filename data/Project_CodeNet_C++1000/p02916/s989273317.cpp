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
        --a[i];
    }
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<int> c(n - 1);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += b[a[i]];
        if(i > 0 && a[i] == a[i - 1] + 1){
            sum += c[a[i - 1]];
        }
    }

    cout << sum << endl;
   return 0;
}