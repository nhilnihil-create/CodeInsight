#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    ll  h, w; cin >> h >> w;
    char field[101][101];
    ll fcnt[101][101];
    fill(fcnt[0], fcnt[101], 999);
    
    rep(i, h+1){
        rep(j, w+1){
            if(i == h || j == w) field[i][j] = 'X';
            else cin >> field[i][j];
        }
    }

    if(field[h-1][w-1] == '#') fcnt[h-1][w-1] = 1;
    else fcnt[h-1][w-1] = 0;
    for(ll x = w-1; x >= 0; --x){
        for(ll y = h-1; y >= 0; --y){
            if(x == w-1 && y == h-1) continue;
            char now = field[y][x], down = field[y+1][x], right = field[y][x+1];
            if(now == '#'){
                if(right == down){
                    fcnt[y][x] = min(fcnt[y+1][x], fcnt[y][x+1]);
                    if(right == '.') 
                        fcnt[y][x]++;
                }else if(now == right && now != down) 
                    fcnt[y][x] = min(fcnt[y][x+1], fcnt[y+1][x]+1);
                else if(now != right && now == down) 
                    fcnt[y][x] = min(fcnt[y][x+1]+1, fcnt[y+1][x]);
                else if(right == 'X'){
                    if(now == down) 
                        fcnt[y][x] = fcnt[y+1][x];
                    else 
                        fcnt[y][x] = fcnt[y+1][x] + 1;
                }else if(down == 'X'){
                    if(now == right) 
                        fcnt[y][x] = fcnt[y][x+1];
                    else 
                        fcnt[y][x] = fcnt[y][x+1] + 1;
                }
            }
            else{
                if(right == 'X') 
                    fcnt[y][x] = fcnt[y+1][x];
                else if(down == 'X') 
                    fcnt[y][x] = fcnt[y][x+1];
                else 
                    fcnt[y][x] = min(fcnt[y+1][x], fcnt[y][x+1]);
            }
        }
    }

    /*
    rep(i, h){
        rep(j, w){
            printf("%c(%2lld)", field[i][j], fcnt[i][j]);
        }
        cout << "\n";
    }
    */
    
    printf("%lld\n", fcnt[0][0]);
        
    return 0;
}