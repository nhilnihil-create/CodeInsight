#include <bits/stdc++.h>
#include<algorithm>
 using namespace std;
 int main(){
     int x,a;
     cin>>x>>a;
     if(x<=9&&x>=0&&a<=9&&a>=0){
     if(x<a){
         std::cout << "0" << std::endl;
     }else{
         std::cout << "10" << std::endl;
     }
     }
 }