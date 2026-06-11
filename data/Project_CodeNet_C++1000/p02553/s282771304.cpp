#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int64_t  a,b,c,d;
    cin >>a >>b >>c >>d;

    int64_t t1,t2,t3,t4;
    t1 = a * c;
    t2 = a*d ;
    t3 = b*c;
    t4 = b*d;

    int64_t max =t1;

    if(max < t2){
        max =t2;
    }
    if(max < t3){
        max =t3;
    }
    if(max < t4){
        max =t4;
    }

    cout<< max <<endl;
}

