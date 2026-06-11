
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
const int MOD = 1e9+7,mxN = 50,INF = 1e9;
int n;
void fastscan(int &number);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fastscan(n);
    int a[n];
    for(int i=0;i<n;i++)
        fastscan(a[i]);
    int best = 1;
    for(int i=0;i<n-1;i++)
    {
        int j=i+1;
        while(j<n&&a[j]<=a[j-1])
            j++;
        if(j-i>best)
            best = j-i;
    }
    cout << best-1;
    
}

void fastscan(int &number) 
{ 
    bool negative = false; 
    register int c; 
    number = 0; 
    c = getchar_unlocked(); 
    if (c=='-') 
    { 
        negative = true; 
        c = getchar_unlocked(); 
    } 
    for (; (c>47 && c<58); c=getchar_unlocked()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 