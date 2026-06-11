#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    long long a,b;
    cin >> a >> b;
    long double ans = a*b;
    if(a==1 || b==1){
        cout << 1 <<endl;
    }else{
        cout << setprecision(100)<<ceil(ans/2) <<endl;
    }
}