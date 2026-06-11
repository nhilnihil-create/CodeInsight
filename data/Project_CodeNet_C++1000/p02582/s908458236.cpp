#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string s;
    cin >> s;

    if ((s == "RSS") || (s == "SSR") || (s == "SRS") || (s == "RSR"))
    {
        cout << 1 << endl;;
    }

    else if((s == "SRR") || (s == "RRS"))
    {
        cout << 2 << endl;
    }

    else if(s == "RRR")
    {
        cout << 3 << endl;;
    }

    else
    {
        cout << 0 << endl;
    }
}