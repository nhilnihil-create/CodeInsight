#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h1,m1,h2,m2,k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int ms1 = m1+h1*60,ms2 = m2+h2*60;
    int sta = max(0,ms2-k-ms1);
    cout << sta << endl;
}
