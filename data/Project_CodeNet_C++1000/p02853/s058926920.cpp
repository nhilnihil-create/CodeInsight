#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>
#include<string.h>
#include<math.h>
using namespace std;
using ll = long long;
int main(){
    int ans = 0;
    int X, Y;
    cin >> X >> Y;
    if(X == 1)ans += 300000;
    if(Y == 1)ans += 300000;
    if(X == 2)ans += 200000;
    if(Y == 2)ans += 200000;
    if(X == 3)ans += 100000;
    if(Y == 3)ans += 100000;

    if(X == 1 && Y == 1)ans += 400000;
    
    cout << ans;
}
