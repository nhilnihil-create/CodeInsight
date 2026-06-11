#include <bits/stdc++.h>

using namespace std;
#define int long long int

signed main() {
int n;
cin>>n;
vector<int> A;
for (int i=0;i<n;i++)
{
    int d;
    cin>>d;
    A.push_back(d);
    
    
}
unordered_map<int,int>mp;
reverse(A.begin(),A.end());
int count=0;
for (int i=n-1;i>=0;i--)
{
    if (mp.find(A[i]+i)==mp.end())
    {
        mp[i-A[i]]++;
    }
    else
    {
        count+=mp[A[i]+i];
        mp[i-A[i]]++;
    }
}
cout<<count;
}

