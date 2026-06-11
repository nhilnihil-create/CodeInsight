//AC
#include<bits/stdc++.h>
using namespace std;

int main(){
    int buf;
    for(int i = 1; i <= 5; ++i){
        cin >> buf;
        if(buf == 0){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}