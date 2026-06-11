// CPP to find nim-game winner
#include <iostream>
#include <math.h>
using namespace std;

// function to find winner of NIM-game
int main(){

    long long int a,b,i,res,ans,j,n;
    cin >> n;
    for(i=sqrt(n);i>1;i--){
        if(n%i==0) break;
    }
    a = i;
    b = n/i;
    ans = a+b-2;
    cout << ans;
}
