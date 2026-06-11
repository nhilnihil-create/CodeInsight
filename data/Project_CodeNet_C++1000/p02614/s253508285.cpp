#include <iostream>
#include <string>
using namespace std;

//H行W列のどこかの行、列(複数でも良い)を赤で塗りつぶす
//黒いマスがK個残る塗り方は何通り
int main(){
    int H,K,W;
    cin >> H >> W >> K;
    string c[H];
    int count=0;

    for(int i=0;i<H;i++){
        cin >> c[i];
    }
   
    for(int bit_l=0; bit_l < (1<<H); ++bit_l){
        for(int bit_c=0; bit_c < (1<<W); ++bit_c){
            int black=0;
            for(int i=0;i<H;++i){
                for(int j=0;j<W;++j){
                    if(!((bit_l & (1<<i)) || (bit_c & (1<<j)) || c[i][j]=='.')){
                        ++black;
                    }
                }
            }
            if(black==K){
                ++count;
            }
        }
    }
    cout << count << endl;
}