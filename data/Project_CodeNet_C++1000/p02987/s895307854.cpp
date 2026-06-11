#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
#define f first
#define s second
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;
const double eps=1e-9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt2=0;
    vector<int> freq(26);
    string s;
    cin>>s;
    for(int i=0;i<4;i++)
        freq[s[i]-'A']++;
    for(int i=0;i<26;i++)
        cnt2+=(freq[i]==2);
    cout<<(cnt2==2?"Yes":"No");
    return 0;
}

