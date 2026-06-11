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

int main(){
   IOS;
 /*    #ifndef ONLINE_JUDGE
         freopen("in.txt",  "r",  stdin);
         freopen("out.txt", "w", stdout);
     #endif */
 	long int x,y,a,b,c;
 	cin>>x>>y>>a>>b>>c;

 	vector<long int> red(a),green(b),colorless(c);

 	for(long int i = 0; i < a; i++)
 		cin>>red[i];

 	for(long int i = 0; i < b; i++)
 		cin>>green[i];

 	for(long int i = 0; i < c; i++)
 		cin>>colorless[i];

   priority_queue<long int,vector<long int>,greater<long int>> pq;
   sort(red.begin(),red.end());
   sort(green.begin(),green.end());
   sort(colorless.begin(),colorless.end());

   while(x--){
   	 	pq.push(red.back());
   	 	red.pop_back();
   }

   while(y--){
   	pq.push(green.back());
   	green.pop_back();
   }

   while(colorless.size() && pq.top() < colorless.back()){
   	 pq.pop();
   	 pq.push(colorless.back());
   	 colorless.pop_back();
   }

   long int ans = 0;
   while(pq.size()){
   	ans += pq.top();
   	pq.pop();
   }

   cout<<ans;

   return 0;
}