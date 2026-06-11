#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, k , s; cin >> n >> k >> s;
    
    int rem = s+1;
    if (rem > 1000000000) rem = 1;
    for (int i = 0; i < k; i++) 
        cout << s << " ";
    for (int i = k; i < n; i++) 
        cout << rem << " ";
    cout << endl;
    return 0;
}