#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb push_back
#define ld long double
#define f first
#define s second
#define in insert
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e18 + 5;
const int mod = 1e9 + 7;
const int  N = 2e5 + 314;
const long double pi = 3.1415926535897932384626433832795;
void solve(){
    int n;
    string s;
    cin>>n>>s;
    int cnt=0;
    for(char i = '0'; i <= '9'; i++){
        for(char j = '0'; j <= '9'; j++){
            string x = "";
            x+=i, x+=j;
            for(char l = '0'; l <= '9'; l++){
                string y = x;
                y+=l;
                int z = 0;
                for(int k = 0; k < n; k++){
                    if(s[k]==y[z])z++;
                }
                if(z==3)cnt++;
            }  
        }   
    }   
    cout<<cnt;
}
signed main(){
    speed;
    int t=1;
    //cin>>t;
    while(t--)solve();
}