#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
    int t=1;
    //cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n%2!=0){
            cout << n/2 + 1 << endl;
        }else{
            cout << n/2 << endl;
        }
    }
}