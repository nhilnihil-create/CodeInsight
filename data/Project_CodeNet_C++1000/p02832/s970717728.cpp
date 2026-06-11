#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++);
using namespace std;
using ll = long long;


int main (){
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < (int)(n); i++){
        cin >> a[i];
    }

    int k=1;
    int ans=0;
    int no=0;

    for (int i = 0; i < (int)(n); i++){
        if (a[i] == k){
            k++;
            ans++;
        }
        if (a[i] != 1) no++;
    }

    if (no == n) cout << "-1" << endl;

    if (no != n) cout << n-ans << endl;
}