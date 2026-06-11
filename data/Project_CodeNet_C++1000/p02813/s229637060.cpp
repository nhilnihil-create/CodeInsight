#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb(x) push_back(x)
#define HAYAKU_HAYAKU ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    HAYAKU_HAYAKU; 
    int n;
    cin>>n;
    vi a(n),b(n),c(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for (int i = 0; i < n; i++)
        cin>>b[i];
    for (int i = 0; i < n; i++)
        c[i] = i+1;
    int x = 0,y = 0,i = 1;
    while (next_permutation(c.begin(),c.end()))
    {
        if(c == a)
            x = i;
        if(c == b)
            y = i;
        i++;
        if(x > 0 && y > 0)
            break;
    }
    cout<<abs(x-y);
}