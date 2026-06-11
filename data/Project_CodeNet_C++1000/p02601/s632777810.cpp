#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define repr(i,x,n) for(int i=x; i<(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define INF 1e9
typedef long long ll;
using VI = vector<int>;
using VB = vector<bool>;
using VS = vector<string>;
using graph = vector<vector<int>>;

int main()
{
 int R,G,B,k,cnt=0;
 cin>>R>>G>>B>>k;
while (R>=G)
{
    cnt++;
    G*=2;
}
while (G>=B)
{
    cnt++;
    B*=2;
}
if (cnt<=k)
{
    cout<<"Yes"<<endl;
}
else cout<<"No"<<endl;


    return 0;
}