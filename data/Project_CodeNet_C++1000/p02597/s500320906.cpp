#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main()
{
    int n; cin >> n;
    string s; cin >> s;

    int W_Left = 0; int R_Right = 0;
    int minMoves = INT_MAX;

    for(int i = 0 ; i < n; i++)
    {
        if(s[i] == 'R')
        R_Right++;
    }

    for(int i = 0 ; i < n ; i++)
    {
        minMoves = min(minMoves, max(W_Left, R_Right) );
        if(s[i] == 'W') W_Left++;
        else if(s[i] == 'R') R_Right--;
    }

    minMoves = min(minMoves, max(W_Left, R_Right) );

    cout << minMoves;
}