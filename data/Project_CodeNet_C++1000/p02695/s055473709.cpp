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

struct obj
{
	long int a,b,c,d;
};

long int n,m,q, ans = 0;
vector<obj> v;
vector<long int> cur;

void solve(long int idx){
	if(idx == n + 1){
		long int sum = 0;
		for(auto ele : v){
			if(cur[ele.b] - cur[ele.a] == ele.c)
				sum += ele.d;
		}
		ans = max(ans,sum);
		return;
	}

	for(long int i = cur[idx - 1]; i <= m; i++){
		cur[idx] = i;
		solve(idx + 1);
	}
}

int main(){
   IOS;
 /*    #ifndef ONLINE_JUDGE
         freopen("in.txt",  "r",  stdin);
         freopen("out.txt", "w", stdout);
     #endif */
   
   cin>>n>>m>>q;
   v.resize(q);
   cur.resize(n + 1);

   cur[0] = 1;

   for(long int i = 0; i < q; i++)
   	   cin>>v[i].a>>v[i].b>>v[i].c>>v[i].d;

   solve(1);
   cout<<ans;

   return 0;
}