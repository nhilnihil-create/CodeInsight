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
    ll a, b, c, k, ans;
    cin>>a>>b>>c>>k;
    if(k<=a) ans = k;
    else if(k>a && k<=a+b) ans = a;
    else if(k>a+b && k<=a+b+c) ans = a - (k - (a+b));
    //else if(k>a+b+c) ans = a-c;
    cout<<ans<<"\n";
}