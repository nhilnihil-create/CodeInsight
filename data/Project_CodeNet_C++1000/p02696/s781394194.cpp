#include<bits/stdc++.h>
using namespace std;
int main(){
    int64_t a,b,n;
    cin >> a >> b >> n;
    int64_t c;
    if(n >= b-1) c = (b-1)*a/b;
    else c = n*a/b;
    cout << c << endl;
}
