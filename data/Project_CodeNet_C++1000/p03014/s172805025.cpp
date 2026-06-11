#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int N = 2000 + 5;
ll r[N][N] = {}, l[N][N] = {};
ll u[N][N] = {}, d[N][N] = {};
char arr[N][N];
int main(){
    Hello
    ll h, w, ans = 0;
    cin >> h >> w;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> arr[i][j];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(arr[i][j] == '#') l[i][j] = 0;
            else {
                if(j == 0) l[i][j] = 1;
                else l[i][j] = l[i][j - 1] + 1;
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = w - 1; j >= 0; j--){
            if(arr[i][j] == '#') r[i][j] = 0;
            else{
                if(j == w - 1) r[i][j] = 1;
                else r[i][j] = r[i][j + 1] + 1;
            }
        }
    }
    for(int j = 0; j < w; j++){
        for(int i = 0; i < h; i++){
            if(arr[i][j] == '#') u[i][j] = 0;
            else{
                if(i == 0) u[i][j] = 1;
                else u[i][j] = u[i - 1][j] + 1;
            }
        }
    }
    for(int j = 0; j < w; j++){
        for(int i = h - 1; i >= 0; i--){
            if(arr[i][j] == '#') d[i][j] = 0;
            else{
                if(i == h - 1) d[i][j] = 1;
                else d[i][j] = d[i + 1][j] + 1;
            }
        }
    }
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            if(arr[i][j] == '.')
            ans = max(ans, r[i][j] + l[i][j] + u[i][j] + d[i][j] - 3);
    cout << ans;
    return 0;
}
