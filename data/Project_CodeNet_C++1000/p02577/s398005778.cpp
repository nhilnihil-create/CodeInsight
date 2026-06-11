
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<time.h>
#include<vector>
using namespace std;
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    char c;
    c = getchar();
    long long int ans = 0;
    while(c!='\n'&&c){
        ans += c-'0';
        c = getchar();
    }
    if(ans%9==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
