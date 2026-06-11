#include<bits/stdc++.h>
#define endl "\n"

typedef long long ll;
using namespace std;

//ll const N = 32000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int N, maxx = 0;
    cin >> N;

    map<string, int> mymap;

    for(int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        mymap[str]++;
        if(mymap[str] > maxx)maxx = mymap[str];
    }

    map<string, int>::iterator it;

    for(it = mymap.begin(); it != mymap.end(); it++)
    {
        if(it -> second == maxx)cout << it -> first << endl;
    }

    return 0;
}