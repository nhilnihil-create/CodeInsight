#include<bits/stdc++.h>


using namespace std;
#define max 10005
int main(){
    long h,a;
    cin >> h >> a;
    if(h%a==0) cout << h/a << endl;
    else cout << h/a+1 << endl;
    return 0;
}