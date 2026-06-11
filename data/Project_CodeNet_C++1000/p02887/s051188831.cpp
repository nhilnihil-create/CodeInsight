#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mod 1000000007
#define wi while
#define vl vector<ll>
#define vi vector<int>
#define map map<char,ll>
#define endl "\n"
const int mxN = 200001;
int main()
{
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt = 1;
    for(int i=1;i<s.size();++i)
    {
        if(s[i]==s[i-1])
            continue;
        else
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;

}
