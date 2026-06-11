#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define me memset
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
using namespace std;
typedef pair<int,int> PII;
typedef pair<long,long> PLL;
 
int n,k,c;
string s;
vector<int> L,R;
 
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>k>>c>>s;
 
    for(int i=0;i<s.size();++i){
        if(s[i]=='o') L.pb(i),i+=c;
        if(L.size()==k) break;
    }
    for(int i=s.size()-1;i>=0;--i){
        if(s[i]=='o') R.pb(i),i-=c;
        if(R.size()==k) break;
    }
 
    for(int i=0;i<k;++i){
        if(L[i]==R[k-i-1])
            printf("%d\n",L[i]+1);
    }
 
    return 0;
}