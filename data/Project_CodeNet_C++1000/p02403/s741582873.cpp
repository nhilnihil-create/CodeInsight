#include<iostream>
using namespace std;

int main(){
    int H, W, p, q;
    
   while (true){ cin >> H >> W;
       if (H==0&&W==0){ break;}
       for (p=0; p<H; p++){
           for (q=0; q<W; q++){
               cout << "#";
           }
           cout << endl;
       }cout << endl;
   }
   return 0;
}

