#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,k,s;
    cin >> a >> b >> c >> k;
    s = min(k,a);
    k-=s;
    if(!k){
        cout << s;
        return 0;
    }
    int m = min(k,b);
    if(m==k){
        cout << s;
        return 0;
    }
    k -= m;
    s -= k;
    cout << s;
    return 0;
}