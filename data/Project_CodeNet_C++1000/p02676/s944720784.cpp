/*GRATITUDE*/
//Arise Awake and Stop Not Till the Goal is reached. You are the greatest of all. Hare Krishna
//Break through all barriers..
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ff              first
#define ss              second
#define uint            unsigned long long
#define int             long long
#define double           long double
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define endl            "\n"
#define all(x)             x.begin(), x.end()
#define all_r(x)           x.rbegin(), x.rend()
#define sortall(x)         sort(all(x))
#define sortall_r(x)       sort(all_r(x))  
#define tr(it, a)          for(auto it = a.begin(); it != a.end(); it++)
#define PI                 acos(-1)
#define w(t)              int t; cin>>t; while(t--)
#define for_f(a,b,c)      for(int i=a;i<=b;i=i+c)
#define for_r(a,b,c)      for(int i=a;i>=b;i=i-c) 
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define trace1(x) cout << '>' << #x << ':' << (x) << "\n"
#define trace2(x,y) cout<< '>' << #x << ':' << (x) << " | " << #y << ':' << (y) << "\n"
#define trace3(a,b,c) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define trace4(a,b,c,d) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
void ash_god()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif
}
/*************************************************************************************************/
//Write your functions here..............................



/***************************************************************************************************/

void solve() {
/*Write your code here*/
  
int k; cin>>k;
string s; cin>>s;
if(s.length()<=k) cout<<s;
else {
for_f(0,k-1,1) cout<<s[i];
 cout<<"...";
}

}   
int32_t main()
{
ash_god();
bool tc=0;
if(tc)  {
    w(t) solve();
}
else solve();

return 0;
} 

