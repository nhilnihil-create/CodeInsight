#include<bits/stdc++.h>
using namespace std;
int main(){
    int h1, h2, m1, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int m = 60 * (h2 - h1) + (m2 - m1);
    cout << m - k << endl;
    return 0;
}