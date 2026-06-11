#include<iostream>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    bool ok = false;
    int i, l = n/100;
    for(i=1; i<=l; i++){
        if(n>=(i*100) && n<=(i*105)){
            ok = true;
            break;
        }
    }
    if(ok) cout << "1\n";
    else cout << "0\n";
    return 0;
}