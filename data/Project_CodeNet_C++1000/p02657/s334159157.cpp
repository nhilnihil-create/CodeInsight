#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define fi first
#define sec second
#define pb push_back
#define ll long long int
#define mp make_pair
#define endl '\n'
#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)

long long a;
double b;
long long c;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>a>>b;
    c = (b+0.001)*100;
    a*=c;
    a/=100;
    cout<<a;
}
