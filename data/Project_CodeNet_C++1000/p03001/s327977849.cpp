#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>

#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){return (a % b)? gcd(b, a % b) : b;}
template<typename T> T lcm(T a, T b){return a * b / gcd(a, b);}

void solve_130C(){
    int w, h, x, y;
    cin >> w >> h >> x >> y;

    bool flag = false;
    if(w % 2 == 0 && w /2 == x){
        if(h % 2 == 0 && h / 2 == y){
            flag = true;
        }
    } 

    if(flag){
        printf("%.10f 1\n", (double) w * h / 2);
    } else printf("%.10f 0\n", (double) w * h / 2);
}

int main(void){
    solve_130C();
    
    return 0;
}