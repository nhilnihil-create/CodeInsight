#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool dp[100009];
int x;
bool f(int i){
    if (i==x)
        return 1;
    if (dp[i])
        return 1;
    dp[i]=1;
    bool h=0;
    for (int j=100;j<=105;j++){
        if (i+j<=x&&!dp[i+j])
            h|=f(i+j);
    }
    return h;

}
int main()
{
    FASTINOUT;
    cin>>x;
    if (f(0))
        cout<<1;
    else
        cout<<0;
    return 0;
}
