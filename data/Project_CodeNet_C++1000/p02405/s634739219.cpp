#include <iostream>
using namespace std;

int main(){
    int a, b, x, y;
    while(1){
        cin >> a >> b;
        if(a == 0 && b == 0)break;
        for(int i = 1;i <= a;i++){
            for(int j = 1;j <= b;j++){
                x = i - (i / 2) * 2;
                y = j - (j / 2) * 2;
                if(x == 1 && y == 1 || x == 0 && y == 0)cout << "#";
                if(x == 1 && y == 0 || x == 0 && y == 1)cout << ".";
            }
         cout << endl;
         }
        cout << endl;
    }
    return 0;
}