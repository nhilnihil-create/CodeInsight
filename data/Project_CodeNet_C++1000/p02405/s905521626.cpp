#include<iostream>
#include <stdio.h>
using namespace std;

int main(){
    int H,W;
    int i,j;
           
    for (;;){
        cin >> H >> W;
        if (H==0 && W==0)break;        
        for (i=0;i<H;i++){
            for (j=0;j<W;j++){
                if (i % 2) {
                    if (j !=(W-1)){
                        if (j % 2){
                            cout << "#";
                        }else{
                            cout << ".";
                        }    
                    }else{
                        if (j % 2){
                            cout << "#"<< endl;
                        }else{
                            cout << "." << endl;
                        }
                    }
                } else {
                    if (j !=(W-1)){
                        if (j % 2){
                            cout << ".";
                        }else{
                            cout << "#";
                        }    
                    }else{
                        if (j % 2){
                            cout << "."<< endl;
                        }else{
                            cout << "#" << endl;
                        }
                    }
                }

            }
        }
        cout << endl;
    }
    
    return 0;
}