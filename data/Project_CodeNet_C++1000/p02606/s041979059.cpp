#include<bits/stdc++.h>
using namespace std;
 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 10000000
main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<(b/c)-((a-1)/c);
}