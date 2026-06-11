#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int k;
    cin >> k;
    
    vector<bool> d(1000005,false);

    if(7%k==0){cout << 1 << endl; return 0;}

    int dr = 7;
    int rest = 7;
    ll cnt = 1;
    d[7] = true;

    do{
        cnt++;
        dr *= 10;
        dr %= k;
        rest += dr;
        rest %= k;
        if(d[rest]){cout << -1 << endl; return 0;}
        else d[rest] = true;
    }while(rest!=0);

    cout << cnt << endl;
    return 0;
}