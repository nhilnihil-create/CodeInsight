#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int a,b;
int main() {
    cin >> a >> b;
    int k = (max(a,b) - min(a,b)) / 2 + min(a,b);
    if((max(a,b) - min(a,b)) % 2 ) cout << "IMPOSSIBLE" << endl;
    else cout << k << endl;
    return 0;
}