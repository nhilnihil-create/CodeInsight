#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    string s,t;
    cin>>s>>t;
    int counter=0;
    for (int i=0;i<s.size();i++){
        if (s[i]!=t[i])
            counter++;
    }
    cout<<counter;

    return 0;
}
