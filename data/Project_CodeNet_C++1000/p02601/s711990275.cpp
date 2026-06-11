#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,g,b;
    int k;
    cin >> r >> g >> b;
    cin >> k;
    int good = 0;

    for(int i = 0 ; i < k ; i++){
        if(r >= b){
            b *= 2;
        }else if(r >= g){
            g *= 2;
        }else if(g >= b){
            b *= 2;
        }

        if(r < g && g < b){
            good = 1;
            break; 
        }
    }
    //cout << r << g << b << endl;

    if(good == 1){
        cout << "Yes" << endl; 
    }else{
        cout << "No" << endl;
    }
    return 0;
}