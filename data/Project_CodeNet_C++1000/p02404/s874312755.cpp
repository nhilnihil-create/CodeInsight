#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug" << x << endl;
using namespace std;

int main(){
    int h,w;
    while(cin >> h >> w, h||w){
        rep(i,h){
            rep(j,w){
                if(i == 0 || j == 0 || i == h - 1 || j == w - 1) cout << "#";
                else cout << '.';
            }
            cout << endl;
        }
        cout << endl;
    }
}