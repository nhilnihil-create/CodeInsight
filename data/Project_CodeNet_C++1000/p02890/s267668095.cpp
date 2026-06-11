#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector <int> a(n) ,frq(n);
    for(int&i : a)
        scanf("%d",&i) ,frq[i-1]++;

    sort(frq.begin() ,frq.end());
    vector <int> cfrq = frq;
    for(int i=1; i<n; i++)
        cfrq[i] += cfrq[i-1];

    vector <int> ans(n);
    for(int j=0,i=1; i<=n; i++){
        while(j<n && frq[j]<=i) j++;
        ans[cfrq[j-1]/i + n-j-1] = i;
    }

    for(int i=n-2; ~i; i--)
        ans[i] = max(ans[i] ,ans[i+1]);
    for(int i : ans)
        printf("%d\n",i);
}
