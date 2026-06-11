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
int arr[mx];
int n;

int main()
{
	fast;
	cin>>n;
	int ma=0;
	int s=1;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]>arr[i-1]){
			ma=max(ma,s);
			s=1;
		}else{
			s++;
		}
	}
	ma=max(ma,s);
	cout<<ma-1<<endl;
	return 0;
}