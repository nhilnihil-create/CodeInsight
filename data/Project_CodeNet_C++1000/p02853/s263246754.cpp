#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int X,Y;
    cin >> X >> Y;
    int prize = 0;
    if (X == 3) prize += 100000;
    if (Y == 3) prize += 100000;
    if (X == 2) prize += 200000;
    if (Y == 2) prize += 200000;
    if (X == 1) prize += 300000;
    if (Y == 1) prize += 300000;
    if (X == 1 && Y == 1) prize += 400000;
    cout << prize << endl;
}
