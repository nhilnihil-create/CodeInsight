#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool tris, dable;
int main(){
    int n, a, b, c, d, pang=0,  ping=0;
    string x, y;
    cin  >> n >> a >> b >> c >> d;
    cin >> x;
    for(int i=0; i<n; i++){
        if(i==a-1 || i==b-1){
            y+="&";
        }
        else{
            if(x[i]=='#'){
                y+="#";
            }
            else{
                y+=".";
            }
        }
    }
        
    ping = max(a-1, b-1);
    pang = min(c-1, d-1);
    if(y[c-1]=='#' || y[d-1]=='#' || c==d){
        cout << "No" << endl;
    }
    else if((a>b && c<d) || (a<b && c>d)){
        while(ping <= pang){
            if(y[ping]!='#' && y[ping-1]!='#' && y[ping+1]!='#'){
                tris = true;
            }
            ping++;
        }
        for(int i=a-1; i<c; i++){
            if(y[i]=='#' && y[i-1]=='#'){
                dable=true;
            }
        }
        for(int i=b-1; i<d; i++){
             if(y[i]=='#' && y[i-1]=='#'){
                dable=true;
            }
        }
        if(dable==true){
            cout << "No" << endl;
        }
        else{
            if(tris==true){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }
    else if((a>b && c>d) || (a<b && c<d)){
        for(int i=a-1; i<c; i++){
             if(y[i]=='#' && y[i-1]=='#'){
                dable=true;
            }
        }
        for(int i=b-1; i<d; i++){
             if(y[i]=='#' && y[i-1]=='#'){
                dable=true;
            }
        }
        if(dable==true){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}