#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include<random>
#include <bitset>
#include <cassert>
#include <complex>
using namespace std;
//#define N (1000000000+7)
//#define N 998244353
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<int,P> Q;

int board[505][505];

int main() {
    int n;
    cin>>n;
    vector<ll>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n%2==1){
        cout<<b[n/2]-a[n/2]+1<<endl;
    }
    else{
        ll mi = a[n/2-1]+a[n/2];
        ll ma = b[n/2-1]+b[n/2];
        cout<<ma-mi+1<<endl;
    }
}
