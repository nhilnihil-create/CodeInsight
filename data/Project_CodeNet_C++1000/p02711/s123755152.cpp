#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0) , cin.tie(NULL) , cout.tie(NULL);

    int n;

    cin>>n;

    if(n%10==7 || (n/10)%10==7 || (n/100)%10==7)
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}
