#include<bits/stdc++.h>

using namespace std;
int main(){
    int a,c,b;
    cin >> a >> b >> c;
    int sub = a-b;
    if(sub>c) cout << 0 << endl;
    else cout << c-sub << endl;
    return 0;
}