#include<iostream>
#include<algorithm>
#include<vector>
#include <map>
#include <set>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <cmath>
#include <sstream>
#define Endl endl
#define eof EOF
#define inf 0x3f3f3f3f
#define maxn 10005
 
using namespace std;
typedef long long  ll;
const double pi=acos(-1);
ll GCD(ll a,ll b){return b==0?a:GCD(b,a%b);}



int main(){
    
   
    vector<int>v={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    
    int n;cin>>n;
    n--;
    cout<<v[n]<<endl;
    return 0;
    
}
