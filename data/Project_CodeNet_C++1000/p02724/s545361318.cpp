#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    int n, happ = 0;
    cin >> n;
    while(true){
        if(n - 500 >= 0){
            n -= 500;
            happ += 1000;
        }
        else break;
    }
    while(true){
        if(n - 5 >= 0){
            n -= 5;
            happ += 5;
        }
        else break;
    }
    cout << happ;
    return 0;
}