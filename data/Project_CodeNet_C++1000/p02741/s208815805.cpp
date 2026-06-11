#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long int lli;
#define tc int t;cin>>t;while(t--)
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vll vector<lli>
#define mx 1000000


int main() {
    fastio;
    int a[]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int k;
    cin>>k;
    cout<<a[k-1]<<"\n";
    return 0;
}
