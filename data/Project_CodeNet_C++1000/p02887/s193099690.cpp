#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>

void test_case()
{
    int n;
    string s,ans;
    cin>>n>>s;
    int i=0;
    while(i<n) {
        if(i+1<n && s[i]==s[i+1]) {
            ans+=s[i];
            char c=s[i];
            while(i<n && s[i]==c)
                i++;
        } else {
            ans+=s[i];
            i++;
        }
    }
    cout<<ans.size();
}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
