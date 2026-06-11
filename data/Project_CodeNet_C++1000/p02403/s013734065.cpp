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
                cout << '#';
            }
            cout << endl;
        }
        cout << endl;
    }
}