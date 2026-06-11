#include <bits/stdc++.h>
using namespace std ;
int main()
{
    long long n , k ;
    vector <long long> v ;
    cin >> n >> k ;
    long long temp ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp ;
        v.push_back(temp) ;
    }
    sort(v.begin(), v.end(), greater <int>() ) ;
    if(k >= n)
    {
        cout <<0 << endl ;
    }
    else
    {
        long long sum = 0 ;
        for(auto it = v.begin() + k ; it != v.end() ;it++)
        {
            sum += *it ;
        }
        cout <<sum << endl ;
    }

}
