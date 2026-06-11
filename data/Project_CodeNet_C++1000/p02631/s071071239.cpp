#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <string>
const int mxN=1e5;
const int maxN=5e3;
#define ld long double
#define pb push_back
#define mp make_pair
#define ins insert
#define vi vector<int>

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int c=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        c^=a[i];
    }
    for(int i=0;i<n;i++)
        a[i]^=c;
    for(int i=0;i<n;i++)
        cout << a[i] << " ";    
}