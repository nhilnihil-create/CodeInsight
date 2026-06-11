#include <iostream>
using namespace std;

//piに含まれない整数の内Xに最も近いものを出力
//複数の場合は小さい方を出力
//piが空行の場合もある
int main(){
    int X,N;
    cin >> X >> N;
    int* p = new int[N];
    for(int i=0;i<N;++i){
        cin >> p[i];
    }

    int dis=0;
    while(true){
        int now=X-dis;
        bool exist=false;
        for(int i=0;i<N;++i){
            if(p[i] == now){
                exist=true;
                break;
            }
        }
        if(!exist){
            cout << now << endl;
            break;
        }
        now=X+dis;
        exist=false;
        for(int i=0;i<N;++i){
            if(p[i] == now){
                exist=true;
                break;
            }
        }
        if(!exist){
            cout << now << endl;
            break;
        }
        ++dis;
    }
}