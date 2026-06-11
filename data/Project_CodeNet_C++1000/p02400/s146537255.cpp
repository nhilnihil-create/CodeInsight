#include<iostream>
#include<cmath>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
        double pai=3.141592653589;
        double r;
        scanf("%lf",&r);
        printf("%.8lf %.8lf\n",r*r*pai,r*2*pai);
        return 0;
}