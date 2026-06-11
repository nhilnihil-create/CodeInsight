#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
int main(void){
set<long long> s;
int n,k;
cin>>n>>k;

char kc= '0'+k;
char nc= '0' +n;

string a(n,kc);
string b(k,nc);
if(a<b)
    cout<<a;
else
    cout<<b;
}

