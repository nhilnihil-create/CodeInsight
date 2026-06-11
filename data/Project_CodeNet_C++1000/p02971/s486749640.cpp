#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
#define f first
#define s second
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;
const double eps=1e-9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n),vC(n);
    for(int i=0;i<n&&cin>>v[i];i++)
        vC[i]=v[i];
    sort(vC.rbegin(),vC.rend());
    for(int i=0;i<n;i++)
        cout<<(v[i]!=vC[0]?vC[0]:vC[1])<<"\n";
    return 0;
}
