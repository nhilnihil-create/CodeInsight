#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
 
ll N,M;
 
int main(void)
{
    cin >> N >> M;
    if(N%2==1){
       for(int k=0;k<M;k++){
           cout << k+1 <<" "<< N-k<<endl;
        } 
    }else{
        for(int k=0;k<M;k++){
            if((N-k)-(k+1)<=N/2){
                cout << k+1 <<" "<< N-k-1<<endl;
            }else{
                cout << k+1 <<" "<< N-k<<endl;
            }
        } 
    }
}