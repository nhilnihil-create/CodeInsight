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
const int N=101;
int A[N],B[N];
 int main() { ios_base::sync_with_stdio(false); cin.tie(0);
 int a,b,n;cin>>n;ll compt=0;
 for(int c=1;c<n;++c){
     int cal=n-c;
    // compt+=3;
    //cout<<(sqrt(cal)+1)<<"\n";
     for(int i=1;i*i<=cal;i++){
         
         if(cal%i==0){
             int a=i,b=cal/i;
             //cout<<a<<" "<<b<<" "<<" "<<c<<"\n";
             if(a==b)compt++;
             else compt+=2;
             //compt+=(i==(cal/i))?3:2;
         }
     }
 }
 cout<<compt;
 
return 0;
}