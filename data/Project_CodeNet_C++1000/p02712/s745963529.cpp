#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
long int N;
int main(){
    cin >> N;
    long int count =0;
    for(int i=1;i<=N;i++){
        if(i%3!=0 && i%5!=0){
            count += i;
        }
    }
    printf("%ld\n",count);
}