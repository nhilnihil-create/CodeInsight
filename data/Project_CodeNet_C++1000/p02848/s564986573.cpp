#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ar array

int N;
vector<char>V;
string S;

void init()
{
    for(int i = 0; i < 26; i++)
        V.pb(((char)(i+65)));
}

void solve()
{
    init();
    //print();
    cin>>N;
    cin>>S;

    string res = "";

    for(int i = 0; i < S.length(); i++)
    {
        char ch = S[i];
        int asc = (int)ch;
        int index = asc - 65;

        res += V[(index + N)%26];
    }

    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}