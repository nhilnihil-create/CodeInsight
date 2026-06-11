#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <climits>

long table[1000][10000+1]={};
long A[1000]={};
long B[1000]={};
long H,N;
void init(long As, long Bs)
{
    for(long i=0; i<=10000; i++){
        table[0][i]=Bs*(i/As);
        if(i%As!=0){
            table[0][i]+=Bs;
        }
    }
    for(long i=0; i<1000; i++){
        table[i][0]=0;
    }
}

long min3(long A1, long B1, long C1){
    return std::min(A1,std::min(B1,C1));
}

void solve(){
    for(long i=1; i<N; i++){
        for(long j=1;j<=H; j++){
            table[i][j]=min3(table[i-1][j],table[i-1][std::max((long)0,j-A[i])]+B[i],table[i][std::max((long)0,j-A[i])]+B[i]);
        }
    }
}

int main(){
    std::cin >> H >> N;
    for(long i=0; i<N; i++){
        std::cin >> A[i] >> B[i];
    }
    init(A[0],B[0]);
    solve();
    std::cout << table[N-1][H] << std::endl;
    return 0;
}