#include<iostream>
using namespace std;

int main(){
    int w,h;
    cin >> h >> w;
    while(!(w == 0 && h == 0)){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if((i+j)%2 == 0){
                    cout << "#";
                }else{
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << endl;
        cin >> h >> w;
    }
    return 0;
}