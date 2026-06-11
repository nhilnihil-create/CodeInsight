#include<bits/stdc++.h>
#include<iomanip>
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
void fast(){ ios::sync_with_stdio(false); cin.tie(NULL);}
void file(){ freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);}

double l,a,b,c;
int main()
{
    fast();
    
    
    cin>>l; 
    a = l/3;l-=a;b=l/2;c=l-b;
    cout<<setprecision(20)<<a*b*c;
}
