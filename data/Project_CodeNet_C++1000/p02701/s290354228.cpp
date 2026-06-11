#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   /// https://ideone.com/Fd5s8n

int t;
cin>>t;
map<string,int>mp;
int ans =0;
while(t--){
    string s;
    cin>>s;
    if(!mp[s])
    {
        mp[s]++;
        ans++;
    }

}
    cout << ans << endl;
}
