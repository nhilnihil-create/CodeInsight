#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=20;
map<string , int > mp;
int main()
{   char a[N],b[N];
string s;
    scanf("%s",a);
    scanf("%s",b);
    int x,y;
    scanf("%d%d",&x,&y);
    s=a;
    mp[s]=x;
    s=b;
    mp[s]=y;
    char z[N];
    scanf("%s",z);
    s=z;
    mp[z]--;
    s=a;
    string q=b;
    printf("%d %d",mp[s],mp[q]);
}
