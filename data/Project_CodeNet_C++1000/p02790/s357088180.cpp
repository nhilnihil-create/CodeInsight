#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
int main()
{
   int a, b;
   cin >> a >> b;
   int min = a, max = b;
   if(a > b){
       min = b;
       max = a;
   }
   rep(i, max){
       cout << min;
   }
   cout << endl;
}