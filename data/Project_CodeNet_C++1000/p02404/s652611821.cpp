#include<iostream>
using namespace std;

int main(){
    int w, h;
    while(1){
       cin >> h >> w;
       if(w == 0 && h == 0) break;
       for(int a = 0; a < h; a++){
         for(int b = 0; b < w;b++){
            if( a == 0 || a == h - 1){
                cout << "#";
             }else{
               if( b == 0 || b == w - 1){
                 cout << "#";
                 }else{
                   cout << ".";
                  }    
                }  
               }  
             cout << endl;
             }
           cout << endl;
          }
       return 0;
      }