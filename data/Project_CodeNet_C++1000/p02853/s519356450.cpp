#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
#include<utility>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;

int main(){
    int x, y, ans = 0;
    cin >> x >> y;
    switch (x){
    case 1:
        ans += 3;
        break;
    case 2:
        ans += 2;
        break;
    case 3:
        ans += 1;
        break;
    default:
        break;
    }
    switch (y){
    case 1:
        ans += 3;
        break;
    case 2:
        ans += 2;
        break;
    case 3:
        ans += 1;
        break;
    default:
        break;
    }
    if(x == 1 && y == 1){
        ans += 4;
    }
    ans *= 100000;
    cout << ans << endl;
    return 0;
}
