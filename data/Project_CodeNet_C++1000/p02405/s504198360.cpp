#include <iostream>
using namespace std;

int main(void){
    

    while(1){
        int h = 0;
        int w = 0;
        cin >> h >> w;
    
        if((h == 0) && (w == 0)){
            break;
        }

        for(int i = 0 ; i < h ; i++){
        int toggle = i % 2;
            for(int j = 0 ; j < w ; j++){
                if(toggle == 1){
                    cout << '.';
                    toggle = 0;
                }else{
                    cout << '#';
                    toggle = 1;
                }
            }
            cout << endl;
        }    
        cout << endl;

    }
    return 0;
}