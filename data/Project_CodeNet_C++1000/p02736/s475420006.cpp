#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int n;
int a[MAX];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%1d", &a[i]);
    }
    if(n == 1){
        cout << a[1] << endl;
        return 0;
    }
    n--;
    for(int i = 1; i <= n; i++){
        a[i] = abs(a[i+1]-a[i]);
    }
    int flag = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 1) flag = 1;
    }
    if(!flag){
        for(int i = 1; i <= n; i++){
            a[i] >>= 1;
        }
    }

    int t = 0;
    for(int i = 1; i <= n; i++){
        t ^= (a[i]&1)*(((n-1)&(i-1)) == i-1);
    }
    if(!flag) t <<= 1;
    cout << t << endl;

    return 0;
}