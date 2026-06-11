#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const ll mod = 1e9 + 7;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int>l(n);
    for(int i=0;i<n;i++) cin >> l[i];

    int sum = 0;
    int ans = 1;
    for(int i=0;i<n;i++){
        sum += l[i];
        if(sum <= x) ans++;
    }
    cout << ans << endl;
}