#include <bits/stdc++.h>
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define reprrev(i,a,b) for(int i=b-1;i>=a;i--) // [a, b)
#define reprev(i,n) reprrev(i,0,n)
#define _GLIBCXX_DEBUG

using ll = long long;
using ull = unsigned long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll mod = 1e9+7;
void chmod(ll &M){
  if(M >= mod) M %= mod;
  else if(M < 0){
     M += (abs(M)/mod + 1)*mod;
    M %= mod;
}
}
ll modpow(ll x, ll n){
   if(n==0) return 1;
  ll res=modpow(x, n/2);
 if(n%2==0) return res*res%mod;
else return res*res%mod*x%mod;
}
int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  else return GCD(b, a % b);
}

using namespace std;
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
int  main()
{
    string S;
    cin >> S;
    int N = S.length(); 
    if (N == 3) {cout << "Yes" << "\n";}
    else {
        string S_1 = S.substr(0, (N-1)/2);
        string S_2 = S.substr(((N+1)/2), (N-1)/2);
        cerr << S_1 << " " << S_2 << "\n";
        bool check_1 = true, check_2 = true, check_3 = true;;
        
        int N_1 = S_1.size();
        int N_2 = S_2.size();
        for(int i = 0; i < N_1; i++) {
            cerr << S_1[i] << " " << S_1[(((N-1)/2) - 1) - i] << "\n";
            
            if (S_1[i] != S_1[(((N-1)/2) - 1) - i]) {
                check_1 = false;
                break;
            }
        }
        for(int i = 0; i < N_2; i++) {
            if (S_2[i] != S_2[(((N-1)/2) - 1) - i]) {
                check_2 = false;
                break;
            }
        } 

        for(int i = 0; i < N; i++) {
            if (S[i] != S[N-1-i]) {
                check_3 = false;
                break;
            }
        }
        cerr << check_1 << " "  << check_2 << "\n";
        if(check_1==1 && check_2==1 && check_3==1) cout << "Yes" << "\n";
        else cout << "No" << "\n";
        }    
}