#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    string s;
    cin>>s;
    string prev ,curr;
    prev.push_back(s[0]);
    int index =1;
    int ans =1;
    while( index < s.length() )
    {
        curr.push_back( s[index]);
        if( prev != curr )
        {
            ans++;
            prev = curr;
            curr.clear();
        }

        index++;
    }
    cout<<ans;
}