#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];

    b=a;

    sort(a.begin(),a.end(),greater<int>());

    for(int i=0;i<n;i++)
    {
        cout<<(b[i]==a[0]?a[1]:a[0])<<"\n";
    }

    return 0;
}
