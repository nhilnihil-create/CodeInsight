// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")



#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define Find order_of_key
// #define at find_by_order
#define x first
#define y second
#define ll long long
#define lll __int128
#define ull unsigned long long
#define ulll unsigned __int128
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define gu getchar_unlocked()
#define pu putchar_unlocked()
#define all(x) x.begin(),x.end()
#define endl '\n'

const int mx=100010;
ll arr[mx];
int n;
int main()
{
	memset(arr,5,sizeof arr);
	cin>>n;
	for(int i=1;i<n;i++){
		ll a;
		cin>>a;
		arr[i-1]=min(arr[i-1],a);
		arr[i]=min(arr[i],a);
	}
	ll s=0;
	for(int i=0;i<n;i++)s+=arr[i];
		cout<<s<<endl;
	return 0;
}