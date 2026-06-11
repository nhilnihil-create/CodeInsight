#include <iostream>

int main()
{
    long X[2];
    std::cin >> X[0] >> X[1];
    long money=0;
    for(long i=0; i<2; i++){
        if(X[i]==1){
            money+=300000;
        }else if(X[i]==2){
            money+=200000;
        }else if(X[i]==3){
            money+=100000;
        }
    }
    if(X[0]==1 && X[1]==1){
        money+=400000;
    }
    std::cout << money << std::endl;
    return 0;
}