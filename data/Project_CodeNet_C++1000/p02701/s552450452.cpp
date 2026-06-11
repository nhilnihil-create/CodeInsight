#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    set<string>st;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        st.insert(s);
    }
    cout<<st.size()<<endl;
}
