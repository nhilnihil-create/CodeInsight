#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> // sort
#include <map> // pair
#include <bitset>
using namespace std;

int pownum;

int main(){

    int S;

    cin >>S;

    uint64_t DpN[2001] = {};
    uint64_t sumDpN[2001] ={};


    DpN[0]=0;
    sumDpN[0]=0;
    DpN[1]=0;
    sumDpN[1]=0;
    DpN[2]=0;
    sumDpN[2]=0;

    for(int i=3;i<=S;++i){
        DpN[i] = 1;
    }

    for(int i=3;i<=S;++i){
        DpN[i] += sumDpN[i-3];
        sumDpN[i] = sumDpN[i-1] + DpN[i]; 
        sumDpN[i] %= (int)( 1 * pow(10,9) + 7);
    }

    DpN[S] %= (int)( 1 * pow(10,9) + 7);
    cout<< DpN[S] << endl;

}

