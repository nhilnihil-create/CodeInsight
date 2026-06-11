#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1010,M=20010;
 int a[N][N];
 typedef pair<int,int> pii;
 string s[7]={"","Yakk","Doh","Seh","Ghar","Bang","Sheesh"};
int main()
{
    string s;
    cin>>s;
    if(s.back()=='s')
    {
        s+="es";
    }
    else
        s+="s";
    cout<<s<<endl;
    return 0;
}  