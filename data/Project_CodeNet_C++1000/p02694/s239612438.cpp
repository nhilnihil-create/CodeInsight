#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    ll X;
    cin >> X;
    ll sum = 100;
    ll count = 0;
    while(1){
        if ( sum >= X ) {
            break;
        }
        sum += sum / 100;
        count++;
    }
    cout << count << endl;
}
