#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a, 
        const pair<int,int> &b) 
{ 
    return (a.second < b.second); 

} 
#define ll long long int
int main()
{
    int n;
    cin >> n;
    std::vector<int> a;
    std::vector<int> b;

    for( int i = 0; i < n; i++  )
    {
        int ta, tb;
        cin >> ta >> tb;
        a.push_back(ta);
        b.push_back(tb);

    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int ans;

    if( n % 2 == 1  )
    {
        ans = b.at( n / 2  ) - a.at( n / 2  ) + 1;

    }
    else
    {
        ans = b.at( n / 2 - 1  ) + b.at( n / 2  ) - a.at( n / 2 - 1  ) - a.at( n / 2  ) + 1;

    }
    cout << ans;    
}
