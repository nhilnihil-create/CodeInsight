/*    
                                                                             
	1. Practice makes a man perfect.
	2. Let go of the past.
	3. Without pain, without sacrifice, we would have nothing.
	4. Great things never come from comfort zones.
	5. Turn your wounds into wisdom.
	6. No pain ... no palm, no throne, no glory,no cross, no crown.
	7. You never know how strong you are until being strong is your only choice.
	8. Smooth seas do not make skillful sailors.
	9. I am not what happened to me, I am what I choose to become.
	10. No matter how fail life pushes you down, No matter how much you hurt,You can always bounce back.
		
		
	--> This lines keep me motivated.		

	Author:- Gaurang_Kothiya
	
*/
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
#include <bitset>
#include <cstdint>
#include <initializer_list>
 
using namespace std;
using namespace __gnu_pbds;  

#define data_set(type) tree<type,null_type,less<type>,rb_tree_tag,tree_order_statistics_node_update>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define ld long double
#define f(i,x,n) for(int i=x;i<=n;i++)
#define fe(x,v)   for(auto &x :v)
#define nf(i,x,n) for(int i=n;i>=x;i--)
#define all(a)   a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define ook(num) order_of_key(num)
#define fbo(num) find_by_order(num)
#define gcd(a,b) __gcd(a,b)
#define bits(n) __builtin_popcountll(n)
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define RE rend()
#define RB rbegin()
#define B begin()
#define E end()
#define acc(v, x) accumulate(all(v), x)
#define p(a,b) pair<a,b>
#define F first
#define S second
#define sz size()
#define v(x) vector<x>
#define m(a,b) map<a,b>
#define u_m(a,b) unordered_map<a,b>
#define mm(a,b) multimap<a,b>
#define s(a) set<a>
#define us(a) unordered_set<a>
#define ms(a) multiset<a>
#define maxy __LONG_LONG_MAX__
#define miny INT_MIN
#define PI 3.14159265358979323846

const int inf= 1e9 +1;
const int inf64= 1e18 -1;
const int MOD= 1e9 +7;


 
void Solve()
{	
	int a[]={8,7,6,5,4,3,2,1};
	int n;
	cin>>n;
	n -=400;
	cout<<a[n/200];
}
 
signed main() 
{
	speed		

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int q=1;
	//cin>>q;
	
	while(q--)
	Solve();
		
	return 0;
} 