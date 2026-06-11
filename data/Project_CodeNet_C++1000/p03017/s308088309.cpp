#include<bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
int main(){
int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
a--;b--;c--;d--;
string s; cin >> s;
int mx = max(c,d),mn=min(c,d);
int flag = 1,flag2=0;
for (int i = a; i < mx-1; ++i)
{
    if (s[i] == '#'&&s[i+1] == '#')
    {
        flag = 0;
        break;
    }
}

for (int i = b-1; i < mn; ++i)
{
    if (s[i] == '.'&&s[i+1] == '.'&&s[i+2] == '.')
    {
        flag2 = 1;
        break;
    }
}
if (c>d&&flag2==0)
{
   flag = 0;
}
if (flag)
{
    cout << "Yes";
}
else cout << "No";
return 0;
}

