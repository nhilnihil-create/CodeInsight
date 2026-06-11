#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    double pai=3.141592653589,da,db;
    int a,b;
    scanf("%d %d",&a,&b);
    da=static_cast<double>(a);
    db=static_cast<double>(b);
    printf("%d %d %.8lf\n",a/b,a%b,da/db);
    return 0;
}

