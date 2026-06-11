#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=1050;
char a[N];
int main()
{
    scanf("%s",a);
    string s=a;
    int n=s.size();
    if(s[n-1] != 's'){
        s+='s';
    }
    else{
        s+="es";
    }
    printf("%s",s.c_str());

}
