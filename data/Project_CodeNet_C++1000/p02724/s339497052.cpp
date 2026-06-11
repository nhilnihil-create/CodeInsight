#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int x,cnt=0;

    cin >> x;

    cnt=cnt+(1000*(x/500));
    x=x%500;

    cnt=cnt+(5*(x/5));


    cout << cnt << endl;

    return 0;
}
