#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int N,change;
    cin>>N;
    
    if (N<=1000){
        cout<<""<<(1000-N);
    }
    else if (N<=2000 && N>1000){
        cout<<""<<(2000-N);
    }
    else if (N<=3000 && N>2000){
        cout<<""<<(3000-N);
    }
    else if (N<=4000 && N>3000){
        cout<<""<<(4000-N);
    }
    else if (N<=5000 && N>4000){
        cout<<""<<(5000-N);
    }
    else if (N<=6000 && N>5000){
        cout<<""<<(6000-N);
    }
    else if (N<=7000 && N>6000){
        cout<<""<<(7000-N);
    }
    else if (N<=8000 && N>7000){
        cout<<""<<(8000-N);
    }
    else if (N<=9000 && N>8000){
        cout<<""<<(9000-N);
    }
    else if (N<=10000 && N>9000){
        cout<<""<<(10000-N);
    }
    else {
        return 0;
    }
    
    return 0;
}