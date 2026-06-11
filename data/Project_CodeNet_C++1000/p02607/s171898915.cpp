#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i<=n; ++i)
    {
        int v;
        cin >> v;
        if(i&1 && v&1)cnt++;
    }
    cout << cnt << endl;

    return 0;
}
