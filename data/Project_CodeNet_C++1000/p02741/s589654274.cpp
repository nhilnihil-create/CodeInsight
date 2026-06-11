#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define mod 1000000007

#define out1(a) cout<<#a<<" "<<a<<endl
#define out2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define out3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl

#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
 
using namespace std;

signed main()
{
    fast;
    int a[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

    int k;
    cin>>k;

    cout<<a[k-1]<<endl;
    return 0;
}