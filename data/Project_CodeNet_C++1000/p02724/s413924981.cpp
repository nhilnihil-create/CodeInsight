#include <bits/stdc++.h>
using namespace std;
#define ll long long int



int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("../input.txt","r",stdin);

    int X;
    cin >> X;
    int c_500,c_5;
    c_500 = X/500;
    X = X - c_500*500;
    c_5 = X/5;

    cout << c_500*1000 + c_5*5 << "\n";


}