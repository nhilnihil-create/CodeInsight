#include <iostream>

 
int gcd(int a, int b){
   if(a<b) return gcd(b,a);
   int r;
   while(r=a%b){
      a = b;
      b = r;
   }
   return b;
}

int gcd(int a, int b, int c){
   return gcd(gcd(a, b), c);
}

int main(){
   int K;
   std::cin >> K;

   int sum = 0;
   for(int i=1; i<=K; ++i){
      for(int j=1; j<=K; ++j){
	 for(int k=1; k<=K; ++k){
	    sum += gcd(i,j,k);
	 }
      }
   }
   std::cout << sum << std::endl;
   return 0;
}
