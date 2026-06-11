#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
vector<int> v;
int n, b[200009], ans[200009];
int main()
{
    IO
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>b[i];
    for(int i=n; i>=1; i--)
    {
        int sum=0;
        for(int j=i; j<=n; j+=i)
            sum+=ans[j];
        if(sum%2!=b[i]%2){
            ans[i]=1;
            v.push_back(i);
        }
    }
    cout<<v.size()<<"\n";
    reverse(v.begin(),v.end());
    for(auto i : v)
        cout<<i<<" ";
}
