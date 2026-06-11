#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> // fixed, setprecision 
#include <math.h> // double sqrt
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
//最大公約数
unsigned long gcd(unsigned long a, unsigned long b)
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



//最小公倍数
unsigned long lcm(unsigned long a, unsigned long b)
{
   return a * b / gcd(a, b);
}


int main(){
   unsigned long A,B,C,D;
   cin>>A>>B>>C>>D;
   unsigned long c,d,cc,dd,E,e,ee;
   if(A%C==0)c=A/C-1;
   else c=A/C;
   if(A%D==0)d=A/D-1;
   else d=A/D;
   E=lcm(C,D);
   if(A%E==0)e=A/E-1;
   else e=A/E;

   cc=B/C;
   dd=B/D;
   ee=B/E;

   cout<<-cc+c-dd+d+ee-e+B-A+1;
   return 0;
   
}