#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> a(n,0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int lim=min(k,43);
    for(int i = 0; i < lim; i++) {
        vector<int> na(n,0);
        for(int j = 0; j < n; j++) {
            int l=max(0,j-a[j]);
            int r=min(n-1,j+a[j]);
            na[l]++;
            if(r+1<n) na[r+1]--;
        }
        for(int j = 1; j < n; j++) {
            na[j]+=na[j-1];
        }
        swap(a,na);
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}