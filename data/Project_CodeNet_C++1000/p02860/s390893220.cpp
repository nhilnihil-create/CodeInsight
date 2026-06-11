#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define forN(i, n) for(int i = 0; i <n ; ++i)
#define endl "\n"
#define noob (main)
typedef long long ll;
using namespace  std;
typedef vector<ll> vi;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int N = 1e7 +100 ;
bool prime[N];
vector<ll>v;

int noob(){
    fastIO;
    int n ;
    cin>>n;
    string s;
    cin>>s;
    if(n%2){
        cout<<"No";
        return 0;
    }
    string s1 = s.substr(0,n/2);
    string s2 = s.substr(((n/2)));
//    cout<<s1<<" "<<s2;
    if(s1==s2){
        cout<<"Yes";
    }
    else cout<<"No";
}