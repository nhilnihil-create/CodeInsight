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
    double ans = ceil(n / 2.0);
    ans = ans / n;
    printf("%.6f\n",ans);

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
