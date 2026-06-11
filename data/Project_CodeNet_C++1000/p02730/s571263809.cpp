

#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pb push_back
#define eb emplace_back
#define sll set<ll>
#define ins insert
#define rep(i,n) for(int i=0;i<n;i++)
#define vpp vector<pair<int,int>>
#define mp make_pair
#define ft first
#define sc second
#define gp " ";
#define MAX 9999999
#define MOD 1000000007
#define mnn(v2) *min_element(v2.begin(),v2.end());
#define mxx(v2) *max_element(v2.begin(),v2.end());
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t,i,j,n,c=0,d=0;
    string s,a,b,k;
    cin>>s;
    a=s;
    n=s.size();
     for(i=0;i<(n-1)/2;i++)
          b+=s[i];
     for(i=(n+3)/2-1;i<n;i++)
          k+=s[i];
    reverse(s.begin(),s.end());
                  string ru,an;
           ru=b;an=k;
           reverse(b.begin(),b.end());
           reverse(k.begin(),k.end());
    if(a==s && ru==b && an==k)
    {
              c=1;
    }
    //cout<<s<<" "<<b<<" "<<k;
   if(c==1)cout<<"Yes";
          else cout<<"No";
}
