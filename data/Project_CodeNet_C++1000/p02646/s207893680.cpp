#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long int a,b,v,w,t,distance0,distance1;

    cin >> a >> v >> b >> w >> t;

    distance0 = abs(a-b);
    distance1 = (v-w) * t;
    if(distance0 <= distance1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}