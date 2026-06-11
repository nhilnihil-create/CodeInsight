#include<iostream>
#include<cstdio>
using namespace std;
int cnt;
int a,b,c;
void solve(){
    for(int i=a;i<=b;i++)
    {
        if(i>c)return ;
        if(c%i==0)cnt++;
    }
}
int main()
{
    cnt=0;
    cin>>a>>b;
    //solve();
    cout<<a/b<<' '<<a%b<<' ';printf("%.5f",(double)a/b);cout<<endl;
}