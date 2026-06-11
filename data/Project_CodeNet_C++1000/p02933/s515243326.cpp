#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using namespace std;
const long long INF = 1LL << 60;

template<class T> bool chamin(T& a,T b)
{
    if(a>b)
    {
        a = b;
        return true;
    }
    return false;
}

template<class T> bool chamax(T& a,T b)
{
    if(a<b)
    {
        a = b;
        return true;
    }
    return false;
}



int main() 
{
    int a;
    string s;
    cin >> a >> s;
    if(a>=3200)
    {
        cout << s << endl;
    }
    else
    {
        cout << "red" << endl;
    }

    return 0;
}

