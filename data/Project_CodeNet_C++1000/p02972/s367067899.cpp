#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> num(n+1),a(n+1);
    rep(i,n) cin >> a[i+1];
    for(int i = n;i>=1;i--){
        int number = 0;
        for(int j = 2*i;j<=n;j+=i){
            number += num[j];
        }
        if(number%2 != a[i]) num[i] = 1;
    }
    int total = 0;
    for(int i = 1;i<=n;i++) total += num[i];
    cout << total << endl;
    for(int i = 1;i<=n;i++){
        if(num[i] == 1) cout << i << endl;
    }

}
