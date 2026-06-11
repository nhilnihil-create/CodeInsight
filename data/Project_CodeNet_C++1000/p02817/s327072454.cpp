#include <bits/stdc++.h>
using namespace std;
void sortString(string &str)
{
   sort(str.begin(), str.end());
   cout << str;
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<t<<s;
    return 0;
}
