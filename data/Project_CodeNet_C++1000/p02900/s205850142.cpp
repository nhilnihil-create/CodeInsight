#include<bits/stdc++.h>
using namespace std;
bool check(long n) 
{ 
    // Corner cases 
    if (n <= 0)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (long i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
long get_factors(long a,long b)
{
    long n = __gcd(a, b); 
  
    // Count divisors of n. 
    long result = 0; 
    for (long i=1; i<=sqrt(n); i++) 
    { 
        // if 'i' is factor of n 
        if (n%i==0) 
        { 
            // check if divisors are equal 
            if (n/i == i&&check(i)) 
                result += 1; 
            else {
                if(check(i))
                    result += 1; 
                if(check(n/i))
                    result+=1;
            }
            
        } 
    } 
    return result; 
}
int main()
{
    long a,b;
    cin>>a>>b;
    long count;
    count=get_factors(min(a,b),max(a,b));
    cout<<count<<endl;
}