#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;
typedef long long ll;


int main(){

 int n; cin>>n;
 vector<int>v(n);

 for(int i=0;i<n;i++)
    cin>>v[i];

vector<int>left(n,0);
vector<int>right(n,0);

for(int i=1;i<n;i++)
    left[i] = max(left[i-1],v[i-1]);

 for(int i=n-2;i>=0;i--)
    right[i] = max(right[i+1],v[i+1]);

 for(int i=0;i<n;i++)
 cout<<max(left[i],right[i])<<endl;


return 0;
}
