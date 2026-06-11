#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector <string> vs;

#define forl(i,a,b) for (int i = a; i < b; i++)
#define rfor(i,b,a) for (int i = b; i >= a; i--)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define sumup(x) accumulate(x.begin(), x.end(), 0)
#define PI 3.141592653589793238
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin>>s>>t;
    t = t.substr(0,s.length());
    if(s==t) cout<<"Yes\n";
    else cout<<"No\n";
}