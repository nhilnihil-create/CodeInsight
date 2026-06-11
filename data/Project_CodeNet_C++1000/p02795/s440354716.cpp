#include <iostream>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
int main(void){
    int W,H,N;
    cin >> H >> W >> N;
    cout << (N + max(H,W) - 1) / max(H,W) << endl; 
}
