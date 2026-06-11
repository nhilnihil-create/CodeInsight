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
    int q ;
    cin >> s ;
    cin >> q ;
    bool turn = false ; 
    string back ;
    string front ; 
    rep(i, q){
        int t ;
        cin >> t ;
        if(t == 1){
            if(turn){
                turn = false ;
            }
            else {
                turn = true ;
            }
        }
        if(t == 2){
            int f ;
            string c ;
            cin >> f >> c ;
            if(turn){
                if(f == 1){
                    back = back + c;
                }
                else {
                    front = c + front ;
                }
            }
            else{
                if(f == 1){
                    front = c + front ;
                }
                else {
                    back = back + c ;
                }

            }
        }
    }
    s = front + s + back ;
    if(turn){
        reverse(s.begin(), s.end()) ;
    }
    cout << s << endl ;
    return 0 ;
}  