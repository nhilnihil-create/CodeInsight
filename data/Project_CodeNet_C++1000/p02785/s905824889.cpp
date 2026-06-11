#include <bits/stdc++.h>
using namespace std;
int main(void){
    int k,n,i;
    long long int c=0,h[1000000];
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> h[i];
    }
    sort(h,h+n,greater<int>());
    for(i=k;i<n;i++)
    {
        c+=h[i];
    }
    {
        cout << c << endl;
    }

    return 0;

}
