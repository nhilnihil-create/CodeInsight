#include <bits/stdc++.h>
using namespace std;
int main(void){

    int a, h;
    cin >> a >> h ;
    
    int s;
    for(int i = 0; i < h ; i++){
        cin >> s ;
        a -= s;
    }

    if(a < 0){
        cout << -1 << endl;
    } else {
        cout << a << endl;
    }
    
}
