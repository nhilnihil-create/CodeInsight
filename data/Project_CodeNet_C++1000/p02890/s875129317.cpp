#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
struct edge {int to,costa,costb;};

signed main() {
 int n;
 cin>>n;
 int x[n+1]={},a;
 for(int i=0;i<n;i++){
     cin>>a;
     x[a]++;
 }
priority_queue<int> v;
for(int i=1;i<=n;i++)if(x[i]!=0)v.push(x[i]);

int m=n,j=0;
for(int i=1;i<=n;i++){
    while(!v.empty()&&m/(i-j)<v.top()){
        m-=v.top();
        v.pop();
        j++;
    }
    cout<<m/(i-j)<<endl;
}


return 0;
}
