#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std ;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0);
    cout.tie(0);
    int n ;
    vector <int> v;
    cin >> n ;
    int x = n ;
    while(n--)
    {
        int temp ;
        cin >> temp ;
        v.push_back(temp) ;
    }
    int cnt = 0 ;
    int least = 1e7 ;
    for(int i = 0 ; i < x ; i++)
    {
        if(v[i] < least)
        {
            least = v[i] ;
            cnt++ ;
        }
    }
    cout << cnt << endl ;
}