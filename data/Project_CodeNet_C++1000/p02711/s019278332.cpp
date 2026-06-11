#include<iostream>
using namespace std;
int pow(int m,int n){
     int ret=1;
     for(int i=0;i<n;i++)ret*=m;
     return ret;
}
int main(){
     int N,flag=0;
     cin >> N;
     for(int i=0;i<4;i++){
          if (N/pow(10,2-i)==7)flag++;
          N -= N/pow(10,2-i)*pow(10,2-i);
     }
     if (flag !=0){
          cout << "Yes" <<endl;
     }else{
          cout << "No" <<endl;
     }
}
