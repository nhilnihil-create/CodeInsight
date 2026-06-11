#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mod 1000000007
#define wi while
#define vl vector<ll>
#define vi vector<int>
#define map map<char,ll>
#define endl "\n"
const int mxN = 200001;
int main()
{
    
    int a,b;
    cin>>a>>b;
    if(b+b>=a)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<(a - (2 * b))<<endl;
    }
    
    return 0;

}
