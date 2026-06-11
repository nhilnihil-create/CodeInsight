#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descsort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void)
{
    int m1,d1,m2,d2;
    cin>>m1>>d1>>m2>>d2;
    if((m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12) && d1==31)cout<<1<<endl;
    else if(m1==2 && d1==28)cout<<1<<endl;
    else if((m1==4||m1==6||m1==9||m1==11) && d1==30)cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}