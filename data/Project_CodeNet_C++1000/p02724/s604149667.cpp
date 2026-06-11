#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    ll num;

    cin >> num;

    ll sum = 0;

    if(num >= 500)
    {
        ll rem = num / 500;

        num = num % 500;

        rem = rem * 1000;

        sum += rem;

        num = num / 5;

        ll rem1 = num * 5;

        sum += rem1;

        cout << sum;


    }

    else
    {
        ll rem = num / 5;

        rem = rem * 5;

        sum += rem;

        cout << sum;
    }



}
