#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
int main(void){
   int K;
   int X;
   cin>>K;
   cin>>X;
   for(int i=X-K+1;i<=X+K-1;i++){
       cout<<i<<endl;
   }
}
