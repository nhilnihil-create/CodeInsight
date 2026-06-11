#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;
map<pa,int>mp;
const int N=2e5+100;
int n,m;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int a,b;
    cin>>a>>b;
    if(a>b){
        while(a--) cout<<b;
    }
    else {
        while(b--) cout<<a;
    }
    return 0;
}
