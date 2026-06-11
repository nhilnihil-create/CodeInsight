#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
void dfs(long long n, int k) {
    if(k==11) return;
    v.push_back(n);
    long long a = n%10;
    if(a>=0 && 9>a)  dfs(n*10+a+1,k+1);
    if(a>=0 && 9>=a) dfs(n*10+a,k+1);
    if(a>0 && 9>=a)  dfs(n*10+a-1,k+1);
    return;
}
int main() {
    long long int n;
    cin >> n;
    for(int i=1;i<10;i++) dfs(i,1);
    sort(v.begin(),v.end());
    cout << v[n-1] << endl;
}
