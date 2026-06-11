#include<iostream>
using namespace std;

int main(){
    int H,W;
    while(1){
        cin >> H >> W;
        if(H==0&&W==0) break;
        for(int i=1;H>=i;i++){
            for(int j=1;W>=j;j++){
                if((i+j)%2==0){
                    cout << "#";                    
                }
                else cout << ".";;
                if(W==j) cout << endl;
            }
        }
    cout << endl;
    } 
}
