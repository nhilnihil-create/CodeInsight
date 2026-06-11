#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950


int main () {
    vector<string> vec = {"MON", "TUE", "WED", "THU", "FRI", "SAT","SUN"} ;
    string s;
    cin >> s;
    int ans ;
    rep(i, 7){
        if( s == vec[i]){
            ans = 7 - i - 1;
        }
        if (ans == 0){
            ans = 7;
        }
    }
    cout << ans << endl; 

}
