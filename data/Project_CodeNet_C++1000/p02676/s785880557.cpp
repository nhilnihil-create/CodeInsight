#include <bits/stdc++.h>
using namespace std;
string s;
int k;


int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>k;
    cin>>s;
    //getline(cin,s);
    if (s.size()<=k)
    {
        cout<<s;
    }
    else
    {
        s.resize(k);
        for (int i=0; i<3; i++)
        {
            s.push_back('.');
        }
        cout<<s;
    }

    return 0;
}
