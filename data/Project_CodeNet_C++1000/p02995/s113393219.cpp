#include <iostream>

template <typename T>
T gcd(T a, T b){
   if (b > a){
      std::swap(a, b);
   }
   while (b > 0){
      T tmp = b;
      b = a % b;
      a = tmp;
   }
   return a;
}

int main(){
   long long int A, B, C, D;
   std::cin >> A >> B >> C >> D;
   std::cerr << gcd(C, D) << std::endl;
   long long int all = B-A+1;
   long long int nCmin = all/C;
   long long int nC = (C* (A/C + nCmin+1) > B)? nCmin : nCmin+1;
   long long int nDmin = all/D;
   long long int nD = (D* (A/D + nDmin+1) > B)? nDmin : nDmin+1;
   long long int lcmCD = (C/gcd(C, D))*D;
   long long int nCDmin = all/lcmCD;
   long long int nCD = (lcmCD* (A/lcmCD + nCDmin+1) > B)? nCDmin : nCDmin+1;
   std::cout << all-(nC+nD-nCD) << std::endl;
}

