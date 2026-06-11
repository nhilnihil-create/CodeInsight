#include<iostream>
#include <bits/stdc++.h>
#include<algorithm>
#include <cstring>
#define endl "\n"
#define SRK ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EPS 1e-6
typedef long long ll;
using namespace std;



int main()
{
    SRK;
    int n,x,i;
    cin >> n;
    set <int> st;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        st.insert(x);
    }
    if (st.size() == n)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }



}
