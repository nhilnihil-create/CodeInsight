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
    int cnt = 0;
    for(int i = 0; i < n; i += 2){
        if(a[i]%2 == 1) cnt += 1;
    }
    cout << cnt << endl;
    return 0;
}