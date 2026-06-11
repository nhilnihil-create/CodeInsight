#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 100005
#define pb push_back
#define vit vector<int>::iterator
typedef pair<lint,lint> pii;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    lint x,k,d,v;
    cin>>x>>k>>d;
    x=abs(x);
    if(x/d>=k) cout<<x-k*d;
    else if((k-x/d)%2) cout<<abs(x%d-d);
    else cout<<x%d;
    return 0;
}
/*
1000000000000000 1 10000000000000
*/
