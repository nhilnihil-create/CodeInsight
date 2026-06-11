#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int K;
void input()
{
    cin>>K;
}

int gcd(int a, int b)
{
    int c=a%b;
    while(c!=0){
        a=b; b=c; c=a%b;
    }
    return b;
}

void solve()
{
    int ans=0;
    for(int i=1;i<=K;++i) ans+=i;
    for(int i=1;i<K;++i){
        for(int j=i+1;j<=K;++j){
            ans+=gcd(i,j)*6;
        }
    }
    for(int i=1;i<=K-2;++i){
        for(int j=i+1;j<=K-1;++j){
            for(int k=j+1;k<=K;++k){
                ans+=gcd(gcd(i,j),k)*6;
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}