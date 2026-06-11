#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define INF 1e18L+5
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<long long > vl;
template<typename T>
void show(vector<T> v){
    bool ok=true;
for(auto it:v){

    
   cout<<it<<" ";
    //cout<<it;
}
cout<<"\n";
}
 int main() { ios_base::sync_with_stdio(false); cin.tie(0);
 string s;cin>>s;
 if(s.end()[-1]=='s')s+="es";
 else s+='s';
 cout<<s;
return 0;
}