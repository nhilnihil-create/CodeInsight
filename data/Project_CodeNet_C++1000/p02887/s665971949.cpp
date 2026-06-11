#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define line cout<<"----------------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
const ll mx=200009;
int main()
{
    int n; 
    cin>>n; 
    string str; 
    cin>>str; 
    str.erase(unique(str.begin(),str.end()),str.end());
    cout<<str.size()<<endl; 
}
