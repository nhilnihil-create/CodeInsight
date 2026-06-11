#include <bits/stdc++.h>

using namespace std;
#define M 1005
#define N 15
#define ll long long
int arr[N];


int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin>>x;
        if(x >= k)
            cnt++;
    }
    cout<<cnt<<endl;
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
