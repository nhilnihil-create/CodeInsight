#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <iomanip>

using namespace std;


int main(){
    int N;
    cin >> N;

    int64_t t1,t2,t3;
    t1 = 1;
    t2 = 1;
    t3 = 1;

    for(int i=0;i<N;++i){
        t1 *=10;
        t2*=9;
        t3*=8;

        t1 = t1 % (int)(1*pow(10,9) +7) ;
        t2 = t2 % (int)(1*pow(10,9) +7) ;
        t3 = t3 % (int)(1*pow(10,9) +7) ;

    }

    int64_t num =(t1 -(t2 - t3)*2 -t3) % (int)(1*pow(10,9) +7);
    num += (int)(1*pow(10,9) +7);
    num %= (int)(1*pow(10,9) +7);

    cout << num<<endl;


}

