#include <bits/stdc++.h>

using namespace std;
#define N 100005
#define ll long long
int arr[N];


int main()
{
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
    {
        int x;
        cin>>x;
        arr[x] = i;
    }
    for(int i = 1 ; i <= n ; i++)
        cout<<arr[i]<<" ";
    return 0;
}
/*
2 3
10 1
1
15 1
2
30 2
1 2
*/
