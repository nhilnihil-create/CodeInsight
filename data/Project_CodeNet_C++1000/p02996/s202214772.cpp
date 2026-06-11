#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    vector<pair<int,int> >v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({b,a});
    }
    sort(all(v));
    ll t=0;
    for(int i=0;i<n;i++){
        t+=v[i].second;
        if(t>v[i].first)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;

    return 0;
}
