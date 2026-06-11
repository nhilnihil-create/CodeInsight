#include<iostream>
using namespace std;

int main(){
 while(1){
 int H, W;
 cin >> H >> W;
 if(H == 0 && W == 0) break;

 for(int j = 0; j < W; j ++){
      cout << "#";
    }
 cout << endl;

 for ( int i = 1; i < H-1; i++ ){
    for ( int j = 0; j < W; j++ ){
        if(j == 0 || j == W-1){
            cout << "#";
        } else {
            cout << ".";
        }
    }
   
    cout << endl;
  }
 for(int j = 0; j < W; j ++){
      cout << "#";
    }
 cout << endl;
 cout << endl;
 }
return 0;
} 
