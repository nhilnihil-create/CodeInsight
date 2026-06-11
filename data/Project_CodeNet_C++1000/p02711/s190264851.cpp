#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"

using namespace std;

//ll const N = 100000;

int main()
{
    int N, one, two, three;

    cin >> N;

    one = N % 10;
    N /= 10;

    two = N % 10;
    N /= 10;

    three = N % 10;
    N /= 10;

    if(one == 7 || two == 7 || three == 7)
    {
        cout << "Yes";
    }

    else cout << "No";

    return 0;
}