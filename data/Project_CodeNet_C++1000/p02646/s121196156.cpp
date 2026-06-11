#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void){
    long long a,v,b,w,t;
    cin >> a >> v >> b >> w >> t;
    bool can = false;
    if(v <= w){
        cout << "NO" << endl;
    }else{
        int d = abs(b-a);
        if((v-w)*t >= d){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}