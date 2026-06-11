                           //*****Jai Mata di*****//

#include<bits/stdc++.h>
using namespace std;
#define Nitroboost  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int 
const int mod=1e9+7;
const int N=1e5+15;
#define debug cout<<"Good uptill here"<<endl<<flush;
#define deb(x) cout<<#x<<":"<<x<<endl<<flush;

vector<int>adj[N];
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int h[N];

int main()
{
    Nitroboost;
    int l,r,d;
    cin>>l>>r>>d;
    int d1=(l-1)/d;
    int d2=r/d;
    cout<<d2-d1;
}