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
    cin>>n;
    int p=1000;
    while(p<n) p+=1000;
    cout<<p-n<<endl;
    return 0;
}