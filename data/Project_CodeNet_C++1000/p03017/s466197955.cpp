#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool tris, dable;
int main(){
    int n, a, b, c, d, pang=0,  ping=0;
    string x, y;
    cin  >> n >> a >> b >> c >> d;
    cin >> y;
    a--; b--; c--; d--;
        
    ping = max(a, b);
    pang = min(c, d);

    for(int i=a; i<=c; i++){
        if(y[i]=='#' && y[i-1]=='#'){
            dable=true;
        }
    }
    for(int i=b; i<=d; i++){
        if(y[i]=='#' && y[i-1]=='#'){
            dable=true;
        }
    }

    if(dable==true){
        cout << "No" << endl;
        return 0;
    }
    
    if (c < d) tris = true;
    
    while(ping <= pang){
        if(y[ping]=='.' && y[ping-1]=='.' && y[ping+1]=='.'){
            tris = true;
        }
        ping++;
    }
    
    cout << (tris ? "Yes" : "No") << endl;
    return 0;
}