#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int n,m;
    n =  C/B;
    m =  A/D;

    if( C % B != 0){
        n++;
    }
    if( A % D != 0) {
        m++;
    }

    if(n <= m) {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}