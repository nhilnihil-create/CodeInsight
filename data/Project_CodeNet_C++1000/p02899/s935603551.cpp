#include <bits/stdc++.h>
#define int long long
using namespace std;
#define _READ freopen("input.txt", "r", stdin);
#define _FAST                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
int32_t main()
{
    int n;
    cin>>n;
    vector<vector<int>> ar;
    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        ar.push_back({input,i+1});
    }
    sort(ar.begin(),ar.end());
    for(auto &i:ar)
        cout<<i[1]<<" ";
    return 0;
}