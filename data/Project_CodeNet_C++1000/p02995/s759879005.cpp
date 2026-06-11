#include<iostream>
#include<cmath>

long long gcd(long long a, long long b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

long long lcm(long long a, long long b)
{
   return a * b / gcd(a, b);
}
int main(void){
    long long a, b, c, d;
    std::cin >> a >> b >> c >> d;
    long long s, e;
    auto seekStart = [&](long long i){
        long long tmp = a / i;
        if(a % i != 0) tmp++;
        return i * tmp;
    };
    auto seekEnd = [&](long long i){
        return b / i * i;
    };
    // auto lcm = [&](long long n, long long m){
    //     long long lcm = 1;
    //     long long adiv = std::sqrt(c);
    //     for(int i = 2; i <= adiv; i++){
    //         while(c % i == 0 && d % i == 0){
    //          n /= i;
    //          m /= i;
    //          lcm *= i;
    //         }
    //     }
    //     lcm *= n * m;
    //     return lcm;
    // };
    long long cok = (seekEnd(c) - seekStart(c)) / c + 1;
    long long dok = (seekEnd(d) - seekStart(d)) / d + 1;
    long long cd = lcm(c, d);
    long long cdok = (seekEnd(cd) - seekStart(cd)) / cd + 1;
    long long all = b - a + 1;
    std::cout << all - cok - dok + cdok << std::endl;
    return 0;
}