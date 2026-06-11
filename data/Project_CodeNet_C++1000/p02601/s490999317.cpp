#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c; 

    int k;
    cin >> k;

    int cou = 0;
    for(int i = 0; i < k; i++){
        if(a < b){
            break;
        }

        b *= 2;
        cou++;
    }

    if(cou != k){
        for(int i = cou; i < k; i++){
            if(b < c){
                break;
            }
            c *= 2;
        }
    }

    if(a < b && b < c){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}