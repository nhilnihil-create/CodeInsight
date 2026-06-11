#include <iostream>
using namespace std;
const long long mod = 1e9 + 7 ;


//This is power function which gives us x^y % mod 

long long power(long long x , long long y , long long mod){
 
  // Base Case
  if(y == 0) return 1 ;
  
  long long p = power(x , y/2 , mod)%mod ;
  p = (p * p) % mod ;
  
  if(y & 1){
    p = (x * p) % mod ;
  }
  
  return p ;
}

// This Function give us Inverse of factorial of n .

long long Inversefactorial(long long n ){
  
  // Base case
  if(n <= 0) return 1 ;
  
  long long fact=1;
  
  for(long long i=1 ; i <= n ; i++){
    fact=(fact * i) % mod ;
  }
  
  return power(fact , mod-2 , mod); 
}


//This Function return factorial n % mod 
long long factorial(long long n){
  
  // Base case
  if(n <= 0) return 1 ;
  
  long long fact=1;
  
  for(long long i=1 ; i <= n ; i++){
    fact=(fact * i) % mod ;
  }
  return fact ;
}
long long nck ( long long n , long long k ){
  
 // The value of nCk is n! / (( n- k)! * k!) 
  
  return (((factorial(n) * Inversefactorial(k)) % mod) * Inversefactorial(n - k)) % mod;
}

// Return the total number of ways reach (n , m) from (0 , 0)
long long TotalWays(long long n , long long m){
  
  // Case I : If (n+m)%3!=0 then answer is 0.
  
  if((n + m) % 3 != 0) return 0;
  
  /*Case II : Form the equation x + 2y = n and 2x + y == m , find the value of 
    		x and y and if x < 0 or y < 0 the our answer is zero
  */
  
  long long x = n - (n + m) / 3;
  long long y = m - (n + m) / 3;
  
  if(x < 0 || y < 0)
    return 0;
  
  //Case III : choose y moves from ( x + y ) moves 
  
  return nck (x + y , y) ;
  
}

int main() {
	long long n , m ;
  cin>> n >> m ;
  
  	cout<<TotalWays(n , m)<<endl;
  
    return 0;
}
