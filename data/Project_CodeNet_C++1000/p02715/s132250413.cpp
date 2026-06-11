#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define long long long 
#define PI 3.141592653589793238

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pref_trie;
typedef tree<long int,null_type,less<long int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef cc_hash_table<long int,long int, hash<long int>, equal_to<long int>, direct_mask_range_hashing<long int>, 
hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<true>, true>> ht;
typedef gp_hash_table<long int,long int> HashTable;

const long int MOD = 1e9 + 7;

template <typename T>
T modpow(T base, T exp, T modulus) {
  base = base % modulus;
  T result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) 
      result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp = exp/2;
  }
  return result;
}

int main(){
   IOS;
 /*    #ifndef ONLINE_JUDGE
         freopen("in.txt",  "r",  stdin);
         freopen("out.txt", "w", stdout);
     #endif */
   
   long int n,k;
   cin>>n>>k;

   long int ans = 0;
   vector<long int> dp(k + 1);

   for(long int i = k; i >= 1; i--){
     long int numChoices = k / i;
     dp[i] = modpow(numChoices,n,MOD);

     for(long int j = 2; i * j <= k; j++)
        dp[i] = (dp[i] - dp[i * j] + MOD) % MOD;

     ans = (ans + i * (dp[i])) % MOD;
   }

   cout<<ans;

   return 0;
}