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

long int dp[11][2][10][2];

long int generate(long int idx, string &s, bool tight, long int lastNumber, bool allZero){
  if(idx == s.size())
    return 1;

  if(dp[idx][tight][lastNumber][allZero] != -1)
    return dp[idx][tight][lastNumber][allZero];

  long int upper = (tight)? (s[idx] - '0') : 9;
  long int ans = 0;

  if(idx == 0 || allZero){
    for(long int i = 0; i <= upper; i++)
      ans += generate(idx + 1, s, tight && (i == upper),i, (allZero && !i));
  }
  else{
    for(long int i = 0; i <= upper; i++){
      if(llabs(i - lastNumber) <= 1)
        ans += generate(idx + 1, s, tight && (i == upper), i, (allZero && !i));
    }
  }

  return dp[idx][tight][lastNumber][allZero] = ans;

}

int main(){
   IOS;
 /*    #ifndef ONLINE_JUDGE
         freopen("in.txt",  "r",  stdin);
         freopen("out.txt", "w", stdout);
     #endif */
   
   long int n;
   cin>>n;

   long int be = 0, en = 1e11;
   long int ans = 0;

   while(be <= en){
    long int mid = (be + en) / 2;
    memset(dp,-1,sizeof(dp));
    string s = to_string(mid);
    long int val = generate(0,s,true,0,true) - 1;

    if(val >= n){
      ans = mid;
      en = mid - 1;
    }
    else
      be = mid + 1;
   }

   cout<<ans;
   return 0;
}