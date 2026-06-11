#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()    
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){ 
        cin>>a[i];
        b[i] = a[i];
    }

    sort(a,a+n);
    int swaps = 0;

    for(int i=0;i<n;i++){
        if(a[i]!=b[i]) swaps++;
    }
    if(swaps>2) puts("NO");
    else puts("YES");

}