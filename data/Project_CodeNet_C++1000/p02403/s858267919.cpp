#include <iostream>
using namespace std;

int main(){
    int H[25565] = {0};
    int W[25565] = {0};
    int i;
    do{
        cin >> H[i] >> W[i];
        i++;
    }while(H[i-1] != 0 && W[i-1] != 0);
    for(int j=0;j<i-1;j++){
        for(int k=H[j];k>0;k--){
            for(int l=W[j];l>0;l--){
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;
    }
}