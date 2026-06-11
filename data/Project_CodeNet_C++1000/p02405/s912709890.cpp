#include<iostream>
#include<stdio.h>
using namespace std;

void print_n(){
    
}
void print_r(){
    
}


int main(){
    while(1){
        int h, w;
        cin >> h >> w;
        if(h == 0 && w == 0) break;
        for(int i=0; i<h; i++){
            int j, len;
            if(i%2==0){
                j = 0;
                len = w;
            }else{
                j = 1;
                len = w + 1;
            }
            for(; j<len; j++){
                if(j%2==0){
                    cout << "#";
                }else{
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}