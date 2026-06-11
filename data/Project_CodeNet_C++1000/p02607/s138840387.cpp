#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
int arr[100000]={0};
int main() {
     int x,y=10000;
     long long a=0,d=0;
     cin>>x;
     int arr[x];
     for(int i=0;i<x;i++){
         cin>>arr[i];
         if (((i+1)%2)==1&& (arr[i]%2)==1)
            a++;
     }
     cout<<a;


    }