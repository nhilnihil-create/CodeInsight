#include <iostream>
using namespace std;
int main(void){
    // Your code here!
   int H,W;
   while(cin >> H >> W)
   if(1<=H&&W<=300){
   for(int j=0; j<H; j++){
       for(int i=0; i<W; i++){
           if((i+j)%2==0)
           cout << '#';
           else
           cout << '.';
}
           cout << endl;
}
    cout << endl;
}
}
