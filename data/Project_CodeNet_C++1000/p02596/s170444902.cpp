#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    vector<int> a(k);
    a[0]=7%k;
    for(int i = 1; i < k; i++) {
        a[i] = (a[i-1]*10+7)%k;
    }
    bool jud=true;
    for(int i = 0; i < k; i++) {
        if(a[i]==0){
            cout << i+1 << "\n";
            return 0;
            jud=false;
        }
    }
    if(jud) cout << "-1" << "\n";

    return 0;
}