#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> l(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }
    sort(l.begin(),l.end());
    int cnt=0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                if(l[i]!=l[j] && l[j]!=l[k] && l[k]!=l[i] && l[i]+l[j]>l[k]) cnt++;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}