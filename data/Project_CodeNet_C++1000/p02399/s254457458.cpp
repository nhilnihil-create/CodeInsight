#include<iostream>
#include<cmath>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
        int a,b;
        cin>>a>>b;
        printf("%d %d %.9f\n",a/b,a%b,1.*a/b);
        return 0;
}