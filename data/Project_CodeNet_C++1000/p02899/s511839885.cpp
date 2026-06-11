#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
typedef pair<int,int> pii;
pii a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a,a+n+1);
    for(int i=1;i<=n;i++)
    cout<<a[i].second<<" ";
}