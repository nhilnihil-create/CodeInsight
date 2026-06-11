#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    IOS
    int n;
    cin>>n;
    pair<int,int> a[n];
    for (int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        a[i]=make_pair(ele,(i+1));
    }
    sort(a,a+n);
    for (int i=0;i<n;i++)
    cout<<a[i].second<<" ";
    cout<<endl;
    return 0;
}