#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ins insert
#define vi vector<int>
const int mxN=2e5;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(s.substr(i,3)=="ABC")
            c++;
    }
    cout << c;
}