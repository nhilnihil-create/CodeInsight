#include<iostream>
using namespace std;

int cnt,M,D;

int main(){
    int i,j,d1,d2;

    cnt=0;

    cin >> M >> D;

    for(i=1;i<=M;++i){
        for(j=1;j<=D;++j){
            d1=j/10;
            d2=j%10;
            if(d1>=2&&d2>=2){
                if(d1*d2==i){
                    ++cnt;
                }
            }
        }
    }

    cout << cnt ;

    return 0;
}
