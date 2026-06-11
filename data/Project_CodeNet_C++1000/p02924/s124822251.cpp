#include<iostream>
#define ll long long

int main(){
 ll n;
   std::cin >> n;
   n--;
   ll res = (n*(n+1))/2;
   std::cout << res;
   return 0;
}
