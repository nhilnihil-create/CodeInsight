#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,m,i=0,j,a,min=1000000,ans=0;
    string s;
    cin >> n;
    pair<int,int>p[200020];
    for(i=0;i<n;i++)
    {
        cin >> a;
        p[i]=make_pair(a,i);
    }
    sort(p,p+n);
    for(i=0;i<n;i++)
    {
        if(i!=n-1)
        {
            cout << p[i].second+1 << " ";
        }
        else
        {
            cout << p[i].second+1;
        }
    }
    return 0;
}
