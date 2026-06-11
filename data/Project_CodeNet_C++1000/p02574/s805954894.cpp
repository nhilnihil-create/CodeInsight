//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
#define sz 1000002
int cnt[sz];
int primes[sz + 1];
//ADVANTAGES OF THIS TECHNIQUE IS WHEN THERE ARE MANY QUERIES THEN SQRT(N) TRICK MIGHT NOT WORK INSTEAD WE CAN DO BIG OF LOGN PER QUERY PRIME_FACTORIZATION USING SIEVE METHOD
//SO IT IS ALSO A VERY USEFUL TECHNIQUE
//prime factorization using sieve
void sieve(){
    int i,j;
    for(i = 1;i<=sz;i++) primes[i] = -1;
    for(i = 2;i<=sz;i++){
        if(primes[i] == -1)
        {for(j = i; j <= sz;j += i){
               if(primes[j] == -1){
                   primes[j] = i;
               }
        }
        }
    }
}
int get_prime_factor(int n){
    int fl = 0;
    int temp = -1;
    while(n != 1){
        if(temp != primes[n]){
            temp = primes[n];
            cnt[primes[n]]++;
            if(cnt[primes[n]] > 1) {
                fl = 1;
                break;
            }
        }
        n = n / primes[n];
    }
      return fl;
}
int main(){
   int q,n,fl,i,j;
   sieve();
   cin >> n;
   int a[n];
   for(i = 0;i<n;i++) cin >> a[i];
   int gg =  a[0];
   for(i = 1;i<n;i++) gg = __gcd(gg,a[i]);
   for(i = 0;i<n;i++){
       fl = get_prime_factor(a[i]);
       if(fl == 1) break;
   }
     if(fl == 0) cout << "pairwise coprime" << endl;
     else if(fl == 1 && gg == 1) cout << "setwise coprime" << endl;
     else cout << "not coprime" << endl;
    return 0;
}

