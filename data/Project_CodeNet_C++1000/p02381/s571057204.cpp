#include <bits/stdc++.h>
using namespace std;

int main(void) {
    double n,s[10000];
    while(cin>>n) {
        if(n==0) return 0;
        double ans=0.0,sum=0.0,ave=0.0;
        for(int i=0;i<n;i++) {
            cin>>s[i];
            sum+=s[i];
        }
        ave=sum/n;
        double cal=0.0;
        for(int i=0;i<n;i++) {
            cal+=(s[i]-ave)*(s[i]-ave);
        }
        ans=sqrt(cal/n);
        printf("%.8f\n",ans);
    }
    return 0;
}