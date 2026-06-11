#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

int main(){
    int n, i, a, tem = 0;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> a;
        tem ^= a;
    }
    if(tem) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}