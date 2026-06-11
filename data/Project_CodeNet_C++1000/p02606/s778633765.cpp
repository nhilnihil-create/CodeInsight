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
int main()
{
    Run();
    int r,l,d,cnt=0;
    cin>>r>>l>>d;
    for(int i=r;i<=l;i++)
    {
        if(i%d==0)
            cnt++;
    }
    cout<<cnt;
}
