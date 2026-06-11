#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x,n;
    set <string> s;
    string a;
    cin >> n;


    for(int i =0;i<n;i++)
    {
        cin >> a;
        s.insert(a);



    }
    cout << s.size();


    return 0;
}