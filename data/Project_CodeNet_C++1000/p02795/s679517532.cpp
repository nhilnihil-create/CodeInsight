#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int H,W,N;
    cin >> H;
    cin >> W;
    cin >> N;
    int use = max(H,W);

    cout << (N+(use-1))/use <<endl;
    
    
}
