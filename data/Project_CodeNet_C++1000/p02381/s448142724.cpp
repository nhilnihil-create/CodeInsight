#include<iostream>
#include<stdio.h>
#include<cmath>
 
using namespace std;
int main () {
    int n;
    while(cin >> n,n!=0){
        double ave,hensa[99],sum=0,s[999];
        for(int i=0;n>i;i++){
            cin >> s[i];
            sum+=s[i];
        }
        ave=sum/n;
        sum=0;
        for(int i=0;n>i;i++){
            sum+=(s[i]-ave)*(s[i]-ave);
        }
        printf("%.6f\n",sqrt(sum/n));
    }
}
