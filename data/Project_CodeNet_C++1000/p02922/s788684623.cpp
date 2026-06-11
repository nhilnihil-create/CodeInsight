#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b; cin >> a >> b;
    for(int i=0;;i++){if((a-1)*i+1 >= b){cout << i << endl; break;}}
    return 0;
}