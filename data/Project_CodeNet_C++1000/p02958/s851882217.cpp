// #pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define S second
#define F first

using namespace std;

const int N = 5e5 + 5, M = 1e7 + 5;

int arr[100];

int main()
{
    int n, c = 0;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) scanf("%d", arr + i);
    for(int i = 1 ; i < n ; i++) c += (arr[i] < arr[i - 1]);
    if(c == 0) return puts("YES"), 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            c = 0;
            swap(arr[i], arr[j]);
            for(int i = 1 ; i < n ; i++) c += (arr[i] < arr[i - 1]);
            swap(arr[i], arr[j]);
            if(c == 0) return puts("YES"), 0;
        }
    }
    puts("NO");
    return 0;
}
