#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, n;
    cin >> x;
    if(10<=x) n=x%10;
    else n=x;
    if(n==3) cout << "bon" <<endl;
    else if(n==0 || n==1 || n==6 || n==8) cout << "pon" <<endl;
    else cout << "hon" <<endl;
    return 0;
}
