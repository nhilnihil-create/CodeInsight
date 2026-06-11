#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    cout << min(a+b, min(b+c, c+a)) << endl;
}