#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = 998244353;
const double PI = 3.141592653589793238463;
const int MAXN = 1000030;

int main()
{
    FAST
    int n;
    cin>>n;
    if(n%10==3)
        cout<<"bon"<<endl;
    else if((n%10==8) || (n%10==6) || (n%10==1) || (n%10==0))
        cout<<"pon"<<endl;
    else{
        cout<<"hon"<<endl;
    }
    return 0;
}
