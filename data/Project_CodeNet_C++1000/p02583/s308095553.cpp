#include <algorithm>
#include <iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
typedef long long ll;

int a[105];

bool iseq(int i,int j,int k){
    return a[i] == a[j] || a[i] == a[k] || a[j]==a[k];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n;i++)
        for (int j = i + 1; j < n;j++)
            for (int k = j + 1; k < n;k++)
                if(a[i]+a[j]>a[k] && !iseq(i,j,k))
                    cnt++;
    cout << cnt;
    return 0;
}
