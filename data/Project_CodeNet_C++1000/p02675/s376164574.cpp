#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    n%=10;
    if(n==2||n==4||n==5||n==7||n==9) cout << "hon" << endl;
    else if(n==3) cout << "bon" << endl;
    else cout << "pon" << endl;
    return 0;
}