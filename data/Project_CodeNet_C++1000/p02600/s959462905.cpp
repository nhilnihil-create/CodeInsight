#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 100005
#define pb push_back
#define vit vector<int>::iterator
typedef pair<int,int> pii;
map<int,int>M;
vector<int> V[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if(n>=400 && n<600) cout<<8;
    else if(n>=600 && n<800) cout<<7;
    else if(n>=800 && n<1000) cout<<6;
    else if(n>=1000 && n<1200) cout<<5;
    else if(n>=1200 && n<1400) cout<<4;
    else if(n>=1400 && n<1600) cout<<3;
    else if(n>=1600 && n<1800) cout<<2;
    else if(n>=1800 && n<2000) cout<<1;

    return 0;
}
