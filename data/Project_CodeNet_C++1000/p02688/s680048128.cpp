#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n, k;
    unordered_map<int, int> M;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) M[i]=0;
    for(int i = 0; i < k; i++)
    {
        int d;
        cin >> d;
        for(int j = 0; j < d; j++)
        {
            int a;
            cin >> a;
            M[a]++;
        }
    }
    int cnt=0;
    for(int i = 1; i <= n; i++)
    {
        if(M[i]==0)cnt++;
    }
    cout << cnt;
}
