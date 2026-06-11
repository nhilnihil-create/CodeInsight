#include <bits/stdc++.h>
using namespace std;
#define     LL      long long int
queue<LL>q;
vector<LL>v;
int main()
{
    LL n;
    cin>>n;
    LL bf=n/500;
    cout<<1000*bf+((n%500)/5)*5<<endl;



     return 0;
}
