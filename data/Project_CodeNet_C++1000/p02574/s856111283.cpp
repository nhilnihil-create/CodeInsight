#include <bits/stdc++.h>
using namespace std;
#define soort(v) sort(v.begin(),v.end())
#define foor(i,n) for(int i=0; i<n; i++)
#define vecprint(v){for(int i=0; i<v.size(); i++)cout << v[i] << " ";}
#define arrprint(v, n){for(int i=0; i<n; i++)cout << v[i] << " ";}
long long int gcd(long long int a, long long int b){if(a%b==0)return b;return gcd(b, a%b);}
long long int lcm(long long int a, long long int b){return (a*b)/gcd(a, b);}

int arr[1000007];
bool flag1 = false;


vector<long long> primes;
void SieveOfEratosthenes(int n=1000009)
{

   vector <bool>prime(n+1,true);

   for (int p=2; p*p<=n; p++)
   {

       if (prime[p] == true)
       {

           for (int i=p*p; i<=n; i += p)
               prime[i] = false;
       }
   }


   for (int p=2; p<=n; p++)
      if (prime[p])
        primes.push_back(p);
}


void trial_division4(long long n) {
    vector<long long> factorization;
    map <int,int> mp;
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            // factorization.push_back(d);
            // cout << d;
            if(mp[d]==0){
              if(arr[d]==1){
                flag1 = true;
                break;
              }
              arr[d] = 1;
              mp[d] = 1;
            }
            n /= d;
        }
    }
    if (n > 1){
      if(mp[n]==0){
        if(arr[n]==1){
          flag1 = true;
        }
        arr[n] = 1;
        mp[n] = 1;
      }
    }
    // return factorization;
}


int main(){
  long long n, m;
  bool flag = false;
  cin >> n;
  SieveOfEratosthenes();
  vector<long long> v;
  v.resize(n);

  for(auto &it: v)
    cin >> it;

  m = __gcd(v[0], v[1]);

  trial_division4(v[0]);
  // cout << flag1 << v[0] << endl;
  // arrprint(arr,17);
  trial_division4(v[1]);

  if(m > 1)
    flag = true;

  for(int i=2; i<n; i++){
    trial_division4(v[i]);
    m = __gcd(m, v[i]);
    if(m > 1)
      flag = true;
  }
  if(!flag1)
    cout << "pairwise coprime" << endl;
  else if (m > 1){
    cout << "not coprime" << endl;
  }
  else
      cout << "setwise coprime" << endl;
  // else
    // cout << ""

    return 0;
}
