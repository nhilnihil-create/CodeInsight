#include<bits/stdc++.h>
using namespace std;
int main(){
    long a,b; cin >> a >> b;
    long c = a*b;
    int r;
    while(b != 0){
        r = a%b;
        a = b;
        b = r;
    }
    cout << c/a << endl;
}