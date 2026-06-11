#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    char mp[102][102];
    for(int i = 0; i <= h; i++){
        fill(mp[i],mp[i]+w+1,'.');
    }
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> mp[i][j];
        }
    }
    ll streak[102][102];
    for(int i = 0; i <= h; i++){
        fill(streak[i],streak[i]+w+1,INF);
    }
    streak[0][1] = 0;
    streak[1][0] = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            int newst_u = 0, newst_l = 0;
            if(mp[i][j] == '#'){
                if(mp[i-1][j] == '.') newst_u = 1;
                if(mp[i][j-1] == '.') newst_l = 1;
            }
            streak[i][j] = min(streak[i][j-1]+newst_l,streak[i-1][j]+newst_u);
        }
    }

    cout << streak[h][w] << endl;

    return 0;
}