#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_in_out;
    map <string,int> m;
    map <string,int> :: iterator it;
    multimap <int,string> x;
    multimap <int,string> :: iterator xt;
    set <string> st;
    set <string> :: iterator si;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        it = m.find(s);
        if(it == m.end())
        {
            m.insert(make_pair(s,1));
        }
        else
        {
            m[s]++;
        }
    }
    for(it = m.begin(); it != m.end(); it++)
    {
        x.insert(make_pair(it -> second, it -> first));
    }
    xt = x.end();
    xt--;
    int maxi = xt -> first;
    for(xt = x.begin(); xt != x.end(); xt++)
    {
        if(xt -> first == maxi)
        {
            st.insert(xt -> second);
        }
    }
    for(si = st.begin(); si != st.end(); si++)
    {
        cout << *si << "\n";
    }
}
