#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int j,k;
    cin >>n>>j>>k;
    if(j%n==0 || k%n==0) puts("OK");
    else{
        int s = (j/n)+1;
        if(s*n<=k) puts("OK");
        else{
            puts("NG");
        }
    }
}
