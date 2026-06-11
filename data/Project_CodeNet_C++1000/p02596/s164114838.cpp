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
#define ll long long
using namespace std;

int main()
{
    int k;
    cin>>k;
    ll i = 1;
    ll t = 7;
    while(i<100000000){
        if(t % k == 0){
            cout<<i<<endl;
            return 0;
        }
        t = (t*10+7)%k;
        i++;
    }
    cout<<"-1"<<endl;
    return 0;
}
