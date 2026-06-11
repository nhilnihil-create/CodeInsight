#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 100005
#define pb push_back
#define vit vector<int>::iterator
typedef pair<lint,lint> pii;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string S,T;
    cin>>S>>T;
    lint ans=0;
    for(lint i=0;i<S.size();i++){
        if(S[i]!=T[i]) ans++;
    }
    cout<<ans;
    return 0;
}
