#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x;
    cin>>x;

    int c=(x%100)/5;
    c+=((x%100)%5+4)/5;

    puts(c<=(x/100)?"1":"0");

    return 0;
}
