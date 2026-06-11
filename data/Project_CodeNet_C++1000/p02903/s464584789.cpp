#include<iostream>
using namespace std;
int main()
{
    int H, W, A, B; cin >> H >> W >> A >> B;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(j < A){
                if(i < B)   cout << 1;
                else    cout << 0;
            }else{
                if(i < B)   cout << 0;
                else    cout << 1;
            }
        }
        cout << endl;
    }
}