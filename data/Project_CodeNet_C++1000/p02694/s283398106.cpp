#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll X;
    cin >> X;

    ll money=100;
    int year=0;
    while(true){
        if(money >= X) break;
        money+=money/100;
        year++;
    }

    cout << year << endl;
    return 0;
}