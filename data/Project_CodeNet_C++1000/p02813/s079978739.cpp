#include <iostream>
#include <string>
using namespace std;
int CountOrder(int N,int M,int table[10],int T,int S,int& order){
    if(M == 0){
        if(T == S){
            return order;
        }
        else{
            order++;
            return 0;
        }
    }
    for(int i=1;i<=N;i++){
        if(table[i] == 0){
            table[i] = 1;
            if(CountOrder(N, M - 1, table, T, S * 10 + i, order)){
                return order;
            }
            table[i] = 0;
        }
    }
    return 0;
}
int main(void){
    int N;
    int table[10] = {0};
    int P=0,Q=0;
    
    cin >> N;
    
    for(int i=1;i<=N;i++){
        int x;
        cin >> x;
        P = P * 10 + x;
    }
    for(int i=1;i<=N;i++){
        int x;
        cin >> x;
        Q = Q * 10 + x;
    }
    int order = 1;
    int Pcount,Qcount;
    Pcount = CountOrder(N,N,table,P,0,order=1);
    for(int i=1;i<=N;i++)table[i] = 0;
    Qcount = CountOrder(N,N,table,Q,0,order=1);
    int ans = abs(Pcount - Qcount);
    cout << ans;
}
