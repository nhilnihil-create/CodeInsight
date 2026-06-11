#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x,g=0,br1,br2,broj;
    cin >> x >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    broj=x;
    while(true)
    {
        br1=x-g;
        br2=x+g;
        if(!binary_search(v.begin(),v.end(),br1))
        {broj=br1;break;}
        else if(!binary_search(v.begin(),v.end(),br2))
        {broj=br2;break;}
        g++;
    }
    cout << broj;
}
