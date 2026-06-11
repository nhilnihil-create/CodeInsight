#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define forN(i, n) for(int i = 0; i <n ; ++i)
#define endl "\n"
typedef long long ll;
using namespace  std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int N = 1e4 + 5;
string s , t;

int main(){
    fastIO;
    cin>>s>>t;
    int l = 0 , r  = 0 , ans  = 0 , n = s.size();
    while(r<n && l<n){
        if(s[l] != t[r]){
            ans++;
        }
        r++;
        l++;
    }
    cout<<ans;
}


