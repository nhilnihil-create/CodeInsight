#include<bits/stdc++.h>
#define all(vc) vc.begin(),vc.end()
#define ll long long
#define MIN(a,b) ((a)<(b)) ? (a) : (b)
#define EVEN(a) (a)%2==0 ? 1 : 0
#define fi first
#define se second
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define mxel(vc) max_element(vc.begin(),vc.end())
#define mnel(vc) min_element(vc.begin(),vc.end())
using namespace std;
int MOD = 1e9+7;
long long int ji[300005];
long long int brut = 1e18;
int Search_Binary (int arr[], int left, int right, int key)
{
 int midd = 0;
 while (1)
 {
    midd = (left + right) / 2;
 if (key < arr[midd]){
    right = midd - 1;
 }else if (key > arr[midd]){
    left = midd + 1;
 }else{
    return midd;
 }
 if (left > right){
    return -1;
    }
  }
}
int fDig(int i)
{
   int k;
   do
   {
      k=i;
      i/=10;
   }while(i);
   return k;
}
int gcd (int a, int b) {
           while (b) {
                a %= b;
           swap (a, b);
        }
    return a;
    }
int lcm (int a, int b) {
     return a / gcd (a, b) * b;
    }
int to_int(string s){
    int x;
    stringstream geek(s);
    geek >> x;
    return x;
}
int prim_const( int x){
    vector<bool> prime(x, true);
    prime[0] = prime[1] = false;
    for (int i=2; i * i<=x; ++i){
        if (prime[i]){
            if (i * 1ll * i <= x){
                for (int j=i*i; j<=x; j+=i){
                    prime[j] = false;
                }
            }
        }
    }
    if (prime[x] == true){
        return 1;
    }else{
        return 0;
    }
}
void solve(int n){
    if(n % 2 == 0){
        cout << (n/2)-1;
    }else{
        cout << (n/2);
    }
}
long long int j;
long long int drujba=0;
int main()
{
  cin.tie(0);cout.tie(0);
  int n;
  cin >>n;
  solve(n);
  cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
