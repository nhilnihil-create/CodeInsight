#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<char> st;
    for(int i=0;i<s.size();i++)
    {
        if(st.empty())
            st.push(s[i]);
        else
        {
            if(s[i]!=st.top())
                st.push(s[i]);
        }
    }
    cout<<st.size()<<"\n";

}
