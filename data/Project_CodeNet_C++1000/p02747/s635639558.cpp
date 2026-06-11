#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

bool hitachi(string s)
{
    if (s=="")
    {
        return true;
    }
    else if (s.size() <2)
    {
        return false;
    }
    else if (s.substr(0,2)=="hi")
    {
        return hitachi(s.substr(2));
    }
    else
    {
        return false;
    }
}

int main()
{
    string s;
    cin >> s;
    if (hitachi(s))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
}