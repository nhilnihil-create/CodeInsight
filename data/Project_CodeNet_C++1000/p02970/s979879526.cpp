#include<bits/stdc++.h>

using namespace std;
int main(){
    int a,r;
    cin >> r >> a;
    int ans = 2*a+1;
    cout << (r-1)/(ans)+1 << endl;
    return 0;
}