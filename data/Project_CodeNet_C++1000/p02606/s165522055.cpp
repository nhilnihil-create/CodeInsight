#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 100005
#define pb push_back
#define vit vector<int>::iterator
typedef pair<int,int> pii;
map<int,int>M;
vector<int> V[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int L,R,d;
    cin>>L>>R>>d;
    cout<<R/d-(L-1)/d;
    return 0;
}
