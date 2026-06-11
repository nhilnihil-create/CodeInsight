#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n % 2 == 0)
        printf("0.5000000\n");
    else{
        int p = n / 2;
        p++;
        double ans = (double) p / n;
        printf("%.7f\n",ans);
    }
    return 0;
}