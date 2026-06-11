#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int N=2000000;
const int M=2000;

void Run()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
ll a[N];
int main()
{
    Run();
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2==1&&i%2==0)
            cnt++;
    }
    cout<<cnt;
}
