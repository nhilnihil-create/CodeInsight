#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    ll d;
    cin >> n >> d;
    int cnt = 0;
    for(int i=0;i<n;i++){
        ll x,y;
        cin >> x >> y;
        if(x*x+y*y<=d*d) cnt++;
    }
    cout << cnt << endl;
    return 0;
}