#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &ai : a) cin >> ai;
    int p = 1;
    int roop = -1;
    vector<int> used(n);
    for(int x=0; x<k; x++){
        used[p-1] = x;
        p = a[p-1];
        if(used[p-1] || p == 1){
            k = k - used[p-1];
            k %= x - used[p-1] + 1;
            while(k--){
                p = a[p-1];
            }
        }        
    }
    cout << p << endl;
}