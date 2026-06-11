#include<bits/stdc++.h>
typedef long long ll;
#define  fi0(i,n)  for(int i=0;i<n;i++)
#define   pb()    push_back()
#define   mk()    make_pair()
#define   fst      first
#define   scnd    second
using namespace std;
int f[500], c;
void solve()
{
    int n;
    string ss;
    cin>>n >> ss;
    for(int i=0;i<ss.size();i++){
        if(ss[i]+n>90)ss[i]=ss[i]+(n-26);
        else ss[i]=ss[i]+n;
    }
    cout<<ss<<endl;
}
ll without()
{
}
void pairwise(ll n)
{

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ///int t;cin>>t;while(t--){ solve();}
    solve();
}
