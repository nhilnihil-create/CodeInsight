#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);

    for(int i=0; i<n; i++)
    {
        cin >> s.at(i);
    }

    sort(s.begin(),s.end());

    int cnt=1;
    for(int i=1; i<n; i++)
    {
        if(s.at(i) != s.at(i-1))
            cnt++;
    }

    cout << cnt << endl;

    return 0;

    
}