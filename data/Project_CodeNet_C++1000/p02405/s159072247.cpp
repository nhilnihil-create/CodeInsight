#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug" << x << endl;
using namespace std;

int main(){
    int h,w;
    int check = 0;
    while(cin >> h >> w, h||w){
        rep(i,h){
            if(i % 2 == 0) check = 0;
            else check = 1;
            rep(j,w){
                if(check == 0){
                    cout << '#';
                    check = 1;
                }else{
                    cout << '.';
                    check = 0;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}