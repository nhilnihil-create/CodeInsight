#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>
int fac[9];
void init() {
    int i=0;
    fac[0]=1;
    for(int i=1;i<9;i++)
        fac[i]=i*fac[i-1];
}

void test_case()
{
    int n,a=0,b=0;
    cin>>n;
    int p[n], q[n];
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>q[i];

    do {
        a++;
    } while(prev_permutation(p,p+n));

    do {
        b++;
    } while(prev_permutation(q,q+n));

    cout<<abs(a-b);
}


int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
