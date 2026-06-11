#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int inf = 1e9+7;
const int N = 1e6+9;

int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n;
    cin>>n>>a>>b;
    int ok=0;
    if(a%n==0) ok=1;
    else if(b%n==0) ok=1;
    else {
        int p = a/n;
        if((p+1)*n<=b) ok=1;
    }
    if(ok) cout<<"OK\n";
    else cout<<"NG\n";
    return 0;
}