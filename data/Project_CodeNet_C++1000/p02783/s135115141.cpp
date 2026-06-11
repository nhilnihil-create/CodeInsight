#include<iostream>
using namespace std;
int floor(int n,int m){
     if (n%m==0){
          return n/m;
     }else{
          return n/m+1;
     }
}
int main(){
     int H,A;
     cin >> H >> A;
     cout << floor(H,A) <<endl;
}
