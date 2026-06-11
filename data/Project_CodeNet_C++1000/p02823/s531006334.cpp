#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

int main(){
    ll n,a,b;cin>>n>>a>>b;
    if((a-b)%2==0) cout<<(b-a)/2<<endl;
    else cout<<min(a,n-b+1)+(b-a-1)/2<<endl;
    return 0;
}