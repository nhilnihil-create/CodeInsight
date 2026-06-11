#include<bits/stdc++.h>
using namespace std;
#define maxn (int)1e5+1000
typedef long long ll;

int main()
{
    int a[3];
    for(int i = 0;i < 3;i ++)
        cin >> a[i];
    swap(a[0],a[1]);
    swap(a[0],a[2]);
    for(int i = 0;i < 3;i ++)
        printf("%d%c",a[i], i == 2?'\n':' ');
}
