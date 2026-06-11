#include<bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef set <int> se;
#define endl "\n"
#define for(i,a,b) for(int i = a;i<b;i++)
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define ll long long
#define mod 1000000007
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


void solve(){

string n;
cin>>n;

int sum = 0;

for(i,0,n.size()) sum = sum + (int)(n[i]-'0');


if(sum%9==0) cout<<"Yes";
else
{
    cout<<"No";
}

}
 
 
int main()
{

solve();
 
return 0;
}