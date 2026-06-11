#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <string>
const int mxN=2e5;
const int maxN=5e3;
#define ld long double
#define pb push_back
#define mp make_pair
#define ins insert
#define vi vector<int>

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a.begin(),a.end());
    int ans=0;
    for(int i=0;i<k;i++)
        ans+=a[i];
    cout << ans;
}