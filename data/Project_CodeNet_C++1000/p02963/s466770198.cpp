#include <bits/stdc++.h>
#define ll long long
#define li long int
#define ld long double
#define pl pair<long long, long long>
#define pi pair<int, int>
#define ppl pair<pl, ll>
#define ppi pair<int, pi>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LLFOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define MOD 1000000007
#define M2 998244353
//std::cout <<setprecision(30) << av << endl;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll s;
    cin >> s;
    ll y3, x3;
    ll k = 1e9;
    if(s%k==0){
        x3=0;
        y3=s/k;
    }else{
        x3 = k-(s+k)%k;
        y3 = (s+k)/k;
    }
    cout << "0 0 " << k << " " << 1 << " " << x3 << " " << y3 << endl;
//    cout << k*y3-x3 << endl;


}
