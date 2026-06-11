#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb(x) push_back(x)
#define HAYAKU_HAYAKU ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    HAYAKU_HAYAKU; 
    int n,ans = 0;
    cin>>n;
    string s;
    cin>>s;
    for (int i = 0; i < n-2; i++)
    {
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C')
            ans++;
    }
    cout<<ans;
}