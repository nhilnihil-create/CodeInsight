#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#define FOR(i,N) for(int i=0;i<N;i++)

int main(){
    long long H,W,Q,M=0,cnt=0,max=0,sum=0;
    cin >> H;
    while(true){
        cnt++;
        M += H;
        M = M % 360;
        if(M==0)break;
    }
    cout << cnt <<endl;
}
