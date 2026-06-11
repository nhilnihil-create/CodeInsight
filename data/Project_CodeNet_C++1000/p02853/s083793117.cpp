#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod=1e9+7;

int main(){
    int x, y;
    cin >> x >> y;
    
    int money=0;
    if(x==1)money+=300000;
    else if(x==2) money+=200000;
    else if(x==3) money+=100000;
    if(y==1)money+=300000;
    else if(y==2) money+=200000;
    else if(y==3) money+=100000;

    if(x==1&&y==1)money+=400000;
    
    cout << money;
}