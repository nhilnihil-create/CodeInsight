#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    int n;
    cin >> n;
    int ans = -1;
    for (int i = 0; i < 50000; i++)
    {
        if(n==i*108/100)
        {
            ans = i;
        }
    }
    if (ans==-1)
    {
        cout << ":(" << endl;
        return 0;
    }
    cout << ans << endl;
    
}
