#include <bits/stdc++.h>
#define mod 1000000007
using ll = long long;
using namespace std; 

int main(){
    int n,m; cin >> n >> m;
    int sum=0;
    int ans=0;
    vector<int> A(n);
    for (int i=0;i<n;i++){
        int a; cin >> a;
        A[i]=a;
        sum+=a;
    }
    for (auto val : A){
        if (val*4*m>=sum){
            ans++;
        }
    }
    if (ans>=m) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}

