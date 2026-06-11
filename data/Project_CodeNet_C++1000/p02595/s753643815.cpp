#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 100;
double dis(double a,double b)
{
    return sqrt(a*a+b*b);
}
int main(){
    int n,d;
    cin>>n>>d;
    double x,y;
    int cnt = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>x>>y;
        if(dis(x,y) <= d)cnt++;
    }
    cout<<cnt<<endl;
	return 0;
}
