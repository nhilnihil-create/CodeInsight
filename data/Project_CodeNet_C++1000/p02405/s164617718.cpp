#include<iostream>
using namespace std;
 
int main(){
   int H,W;
    
   while(true){
       cin >> H >> W;
       if( H == 0 && W == 0) break;
       if(H == 1 && W == 1) cout << "#" << endl;
 
       if(H==1 && W != 1){
         for(int j = 1;j < W;j +=2){
               cout << "#" << ".";
           } 
           if(W%2 == 1) cout << "#"; 
           cout << endl;
       }
        
        
       for(int i = 1; i < H; i += 2){
           for(int j = 1;j < W;j +=2){
               cout << "#" << ".";
           }
           if(W%2 == 1) cout << "#";
           cout << endl;
           for(int j = 1;j < W;j +=2){
               cout << "." << "#";
           }
           if(W%2 == 1) cout << ".";
           cout << endl;
       }
       if(H%2 == 1 && H !=1){
               for(int j = 1;j < W;j +=2){
               cout << "#" << ".";
           }
           if(W%2 == 1) cout << "#";
           cout << endl;
           }
       cout << endl;
   }
   return 0;
}