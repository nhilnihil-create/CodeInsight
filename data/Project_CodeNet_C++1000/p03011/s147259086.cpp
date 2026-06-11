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
    int a[5];
    rep(i,3){
        cin>>a[i];
    }
    sort(a, a+3);
    cout<<a[0]+a[1];
    return 0;
}
