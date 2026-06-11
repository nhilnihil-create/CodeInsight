#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n,k;
    cin >> n >> k;
    if(k == 1){
        cout << 0 << endl;
        return 0;
    }
    cout << n-k << endl;
    return 0;
}
