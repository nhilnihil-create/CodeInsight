#include<iostream>
using namespace std;

int A[100][100];
char type[100];
int d[100];//経路の長さ<-初期値15000
int n;

int Dijkstra(int k){
    type[k] = 'B';
    int min = 0;
    for(int i=1; i<n; i++){
        if((A[k][i] != -1) && (type[i] != 'B')){
            type[i] = 'G';
            //長さを調査、短ければ更新
            if(d[k] + A[k][i] < d[i]){
                d[i] = d[k] + A[k][i];
            }
        }
    }
    int FLAG = 0;
    for(int j=1; j<n; j++){
        if(type[j] == 'G'){
            if(FLAG == 0){
                min = j;
            } else {
                if(d[j] < d[min]){
                min = j;
                }
            }
            FLAG = 1;
        }
    }
    if(min == 0){
        return 0;
    } else {
        Dijkstra(min);
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){//Aを-1に初期化,dを最大値に初期化
        d[i] = 100000000;
        type[i] = 'W';
        for(int j=0; j<n; j++){
            A[i][j] = -1;
        }
    }
    //↓↓↓ここで、入力を表の形に代入
    int p, q, r, s;
    for(int i=0; i<n; i++){
        cin >> p;//点の名前
        cin >> r;//隣接点の数
        for(int j=0; j<r; j++){
            cin >> q;//隣接点の名前
            cin >> s;//pとqの間の重み
            A[p][q] = s;
        }
    }
    //↑↑↑

    d[0] = 0;

    Dijkstra(0);

    for(int i=0; i<n; i++){
        cout << i << " " << d[i] <<  endl;
    }
}
