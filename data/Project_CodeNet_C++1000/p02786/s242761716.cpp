#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    
        ll h;
        cin >> h;
        ll height = log(h) / log(2);
        ll ans = 1;
        ll temp = 1;
        for (int i = 1; i <= height; i++) {
            ans = ans * 2;
            temp += ans;
        }
        cout << temp<<endl;
    
}