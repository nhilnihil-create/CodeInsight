#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, i, cnt=0;
    cin >> n;
    int array[n];
    for(i=1;i<=n;++i) {
        cin >> array[i];
        if((i%2) && (array[i]%2)) ++cnt;
    }
    cout << cnt << endl;
    return 0;
}