#include <iostream>
using namespace std;
int main(){
    int H,W;
    while(1){
        cin >> H >> W;
        if(H==0 && W==0) break;
        else{
            if(H%2==0){
                for(int i=0;i<H/2;i++){
                    if(W%2==0){
                        for(int j=0;j<W/2;j++){
                            cout << "#.";
                        }
                        cout << "\n";
                        for(int k=0;k<W/2;k++){
                            cout << ".#";
                        }
                        cout << "\n";
                    }
                    else{
                        for(int j=0;j<(W-1)/2;j++){
                            cout << "#.";
                        }
                        cout << "#\n";
                        for(int k=0;k<(W-1)/2;k++){
                            cout << ".#";
                        }
                        cout << ".\n";
                    }
                }
                
            }
            if(H%2==1){
                for(int i=0;i<(H-1)/2;i++){
                    if(W%2==0){
                        for(int j=0;j<W/2;j++){
                            cout << "#.";
                        }
                        cout << "\n";
                        for(int k=0;k<W/2;k++){
                            cout << ".#";
                        }
                        cout << "\n";
                    }
                    else{
                        for(int j=0;j<(W-1)/2;j++){
                            cout << "#.";
                        }
                        cout << "#\n";
                        for(int k=0;k<(W-1)/2;k++){
                            cout << ".#";
                        }
                        cout << ".\n";
                    }
                }
                if(W%2==0){
                    for(int j=0;j<W/2;j++){
                        cout << "#.";
                    }
                    cout << "\n";
                }
                else{
                    for(int j=0;j<W/2;j++){
                        cout << "#.";
                    }
                    cout << "#\n";
                }
                
            }
        }
        cout << "\n";
    }
    return 0;
}