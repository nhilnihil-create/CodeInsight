#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
 
int main(){
    int k, x;
    cin >> k >> x;
    for(int i = ( x - (k - 1)); i <= (x + (k - 1)); i++){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}