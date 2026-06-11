#include <iostream>
#include <math.h>
using namespace std;
using lld = long long int ;
#define mod 1000000007; 

int main(){
    int H,W,K;
    cin >> H >> W >> K;
    char c[H][W];
    int count = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> c[i][j];
            if(c[i][j]=='#'){
                count++;
            }
        }
    }
    if(K>count){
        cout << 0 <<endl;
        return 0;
    }  
    int ans=0;
    for(int i=0;i<pow(2,H);i++){
        for(int j=0;j<pow(2,W);j++){
            int kcount=0;
            for(int k=0;k<H;k++){
                for(int l=0;l<W;l++){
                    if(((i>>k)%2==0)&&((j>>l)%2==0)){
                        if(c[k][l]=='#'){
                            kcount++;
                        }
                    }
                }
            }
            if(K==kcount){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
    return 0;
}