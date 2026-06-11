#include <iostream>
using namespace std;

int main(void){
    
    for(int i = 0 ; i < 301 ; i++){
        int h = 0;
        int w = 0;
        
        cin >> h >> w;
        
        if( (h == 0) && (w == 0)){
            break;
        }
        for(int j = 0 ; j < h ; j++){
            for(int k = 0 ; k < w ; k++){
                if( (j == 0) || (j == (h - 1)) || (k == 0) || (k == (w -1)) ){
                    cout << '#';
                }else{
                    cout << '.';
                }
            }
            cout << endl;
        }        
        cout << endl;
    }
    
    return 0;
}