#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int H,W,A,B;
    cin >> H >> W >> A >>B;
    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            if(y<B&&x<A){
                cout<<1;
            }else if(y>=B&&x>=A){
                cout<<1;
            }else{
                cout<<0;
            }
         
            
        }
           cout<<endl;
    }

    return 0;
}