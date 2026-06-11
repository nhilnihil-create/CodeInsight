#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j,a,b;
    while(true){
        cin >> a >> b;
        if(a+b==0){
            return 0;
        }
        for(i=0; i<a; i++){
            for(j=0; j<b; j++){
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;
    }
}
