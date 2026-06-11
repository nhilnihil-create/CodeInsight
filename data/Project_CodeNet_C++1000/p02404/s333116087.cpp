#include <iostream>
using namespace std;
 
int main(){
    int h, w;
    while(true){
        cin >> h >> w;
        if(h==0) break;
        for(int j=0;j<h;j++){
            if(j==0 || j==h-1){
                for(int i=0;i<w;i++){
                    cout << "#";
                }
                cout << endl;
            }else{
                for(int i=0;i<w;i++){
                    if(i==0 || i==w-1){
                        cout << "#";
                    }else{
                        cout << ".";
                    }
                }
            cout << endl;
            }
        }
    cout << endl;
    }
}
