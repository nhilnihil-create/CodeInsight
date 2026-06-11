#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int an;
    long long sum = 0;
    int max_n = -1000001;
    int min_n = 1000000;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> an;
        max_n = max(max_n,an);
        min_n = min(min_n,an);
        sum+=an;

    }
    cout << min_n << " " << max_n << " " << sum << endl;
    return 0;
}