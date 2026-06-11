#include<bits/stdc++.h>
#define ll long long
#define S second
#define F first

using namespace std;

const int N = 2e5 + 5, M = 2 * N;

int arr[N], b[N];

int main()
{
    vector<int> v;
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++) scanf("%d", arr + i);
    for(int i = n ; i ; i--)
    {
        int sum = 0;
        for(int j = i + i ; j <= n ; j += i)
        {
            sum += b[j];
        }
        if((sum&1) != arr[i]) b[i] = 1, v.emplace_back(i);
    }
    printf("%d\n", v.size());
    for(int i = 0 ; i < v.size() ; i++) printf("%d%c", v[i], " \n"[i == v.size() - 1]);

    return 0;
}
