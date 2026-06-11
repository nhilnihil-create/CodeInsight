#include<iostream>
#include<cmath>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d %d %.8lf\n",a/b,a%b,a*1.0/b);
        return 0;
}