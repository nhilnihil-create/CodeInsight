#include <iostream>
using namespace std;
int main(){
    int h,w;
    while(1){
        cin >> h >> w;
        if(h==0 && w==0) break;
        else{
            for(int i=0;i<w;i++){
                cout << "#";
            }
            for(int j=0;j<h-2;j++){
                cout << "\n#";
                for(int k=0;k<w-2;k++){
                    cout << ".";
                }
                cout << "#";
            }
            cout << "\n";
            for(int l=0;l<w;l++){
                cout << "#";
            }
            cout << "\n\n";
        }
    }
    return 0;
}