#include<iostream>
#include<algorithm>

using namespace std;

int a[200000];
double sum[200000];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = (a[i] + 1)*a[i]/2/(double)a[i];
        if(i)sum[i] += sum[i - 1];
    }
    double Max = 0;
    for (int i = 1; i <= n; i++) {
        if (i == k - 1)
            Max = max(Max,sum[i]);
        else if (i >= k)
            Max = max(Max, sum[i] - sum[i - k]);
    }
    
    printf("%.121f\n", Max);
}
