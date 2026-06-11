#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace std;
int main(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<max(a*c,max(a*d,max(b*c,b*d)));
    return 0;
}