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
    bool is = false ;
    rep(i, 3){
        if(s[i] == s[i + 1]){
            is = true ;
            break ;
        }
    }
    if(is){
        cout << "Bad" << endl ;
    }
    else {
        cout << "Good" << endl ;
    }
}