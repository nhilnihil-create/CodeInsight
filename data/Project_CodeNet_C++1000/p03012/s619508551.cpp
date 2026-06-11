#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>
#define mp make_pair
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define No cout<<"No"<<endl
#define rep(i,n) for(int i=0;i<n;i++)
#define INF (1<<30)
#define LLINF (1LL<<60)
//#define MOD 998244353
#define MOD 1000000007
#define PI 3.14159265358979
using ll = long long;
using namespace std;

int main(){
    int n,sum[105]={};
    cin>>n;
    rep(i,n){
        int t;
        cin>>t;
        if(i==0)sum[i]=t;
        else sum[i]=sum[i-1]+t;
    }
    int ans=INF;
    rep(i,n){
        int left=sum[i];
        int right=sum[n-1]-sum[i];
        ans=min(ans,abs(left-right));
    }
    cout<<ans;
    return 0;
}
