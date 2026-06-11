#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<char> arr;
    arr.push_back(s[0]);
    for(int i=1;i<s.length();i++)
    {
        if(s[i]!=s[i-1]){arr.push_back(s[i]);}
    }
    cout<<arr.size();
}
