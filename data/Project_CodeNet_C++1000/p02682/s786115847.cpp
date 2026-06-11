#include <bits/stdc++.h>
using namespace std;
int main(void){

    long long a, b, c, k, sum = 0;
    cin >> a >> b >> c >> k ;

    sum += min(a, k);
    sum -= max((long long)0, k - a - b);
    
    cout << sum << endl;    
}
