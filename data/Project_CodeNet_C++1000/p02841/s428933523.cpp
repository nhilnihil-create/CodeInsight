#include<bits/stdc++.h>
using namespace std;
int main(){
    int m1, m2, d1, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    if(m1 + 1 == m2)
        cout << '1' << endl;
    else if(m1 == 12 && m2 == 1)
        cout << '1' << endl;
    else cout << '0' << endl;
    return 0;
}