#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll m;
    cin >> m;
    ll sum = 0;
    ll size = 0;
    for(int i = 0; i < m; i++){
        ll d, c;
        cin >> d >> c;
        sum += d*c;
        size += c;
    }
    cout << size-1+(sum-1)/9 << endl;
}