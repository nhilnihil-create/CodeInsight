#include<bits/stdc++.h>
using namespace std;

using ll = long long;


int main(){
    ll H;
    cin >> H;
    ll cnt = 0ll;
    ll mn = 1;
    while(H > 0ll){
        H /= 2;
        cnt += mn;
        mn *= 2;
    }
    cout << cnt << endl;
}