#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18

int main() {
    string s ;
    cin >> s ;
    int res = 0 ;
    rep(i,4){
        rep(j,4){
            if(i == j){
                continue ;
            }
            else {
                if(s[i] == s[j]){
                    res++ ;
                }
            }
        }
    }
    if(res == 4){
        cout << "Yes" << endl ;
    }
    else {
        cout << "No" << endl ;
    }
}