#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
typedef long long LL;

pair<int,int> a[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i].second=i;
        cin>>a[i].first;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i].second<<" ";
    }
    cout<<endl;
    //system("pause");
}