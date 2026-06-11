#include <bits/stdc++.h>
#define ii pair <int , int>
#define is pair <int, string>
#define ll long long
#define mx 100000
#define sf scanf
#define sf(n) scanf("%d",&n)
#define pf printf
using namespace std;
vector <int> v;

/*int intConvert(string s){
    int n;
    stringstream geek(s);
    geek >> n;
    return n;
}*/

/*string strConvert(int n){
    string s;
    stringstream ss;
    ss << n;
    s=ss.str();
    return s;
}*/


int main(){
    int a,b,c;
    scanf("%d %d %d",&a, &b, &c);
    
    int ans=a+b+c;
    if(ans>=22) pf("bust\n");
    else pf("win\n");

    return 0;
}
