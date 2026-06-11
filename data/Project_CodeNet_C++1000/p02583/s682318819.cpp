#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,br=0,a,b,c;
    cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++)
        cin >> v[i];
    for (int i=0;i<n-2;i++)
        for (int j=i+1;j<n-1;j++)
            for (int k=j+1;k<n;k++)
            {
                a=v[i]; b=v[j]; c=v[k];
                if(a+b>c && b+c>a && a+c>b && a!=b && b!=c && a!=c)
                    br++;
            }
    cout << br;
}
