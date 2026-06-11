#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<climits>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
using namespace std;

int main()
{
    string s;
    cin>>s;
    string p;
    cin>>p;

    int ans = INT_MAX;
    int len = p.length();
    for(int i = 0;i<=s.length()-len;i++)
    {
        int count = 0;
        for(int j = 0;j<len;j++)
        {
            if(p[j]==s[i+j])
            {
                count++;
            }
        }
        ans = min(ans,len-count);
    }
    cout<<ans;
return 0;
}