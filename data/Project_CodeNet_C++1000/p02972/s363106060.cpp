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
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int b[n];
    int count=0;
    for(int i = 0; i < n; i++) {
        int idx=n-i;
        int j=idx-1;
        b[idx-1]=0;
        while(j<n){
            b[idx-1]+=b[j];
            j+=idx;
        }
        if(b[idx-1]%2!=a[idx-1]){
            b[idx-1]=1;
            count++;
        }
        else b[idx-1]=0;
    }
    cout << count << "\n";
    if(count!=0){
        for(int i = 0; i < n; i++) {
            if(b[i]==1)cout << i+1 << " ";
        }
        cout << "\n";
    }

    return 0;
}