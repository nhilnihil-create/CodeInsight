#include <bits/stdc++.h>
using namespace std;

int main(){
    long H,W;
    cin >> H >> W;
    long long board;
    board=H*W;
    if(H==1 || W==1){
        cout << 1 << endl;
    }
    else if(board%2==0){
        cout << board/2 << endl;
    }
    else{
        cout << board/2+1 << endl;
    }
}
