#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    int n, m, sum;
    cin >> n >> m;
    sum = 0;
    vector<int> vec(n);
    rep(i, n)
    {
        cin >> vec.at(i);
        sum += vec.at(i);
    }

    sort(vec.begin(), vec.end(), greater<int>());

    int a = vec.at(m-1) ;
    if(4*m*a<sum)
    {
        cout << "No" << endl ;
    }
    else
    {
        cout << "Yes" << endl ;
    }
    
}