#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    scanf("%d%d", &n,&m);
    if(n == 1 || m == 1) cout<<"1\n";
    else{
        long long c = ((long long)n*(long long)m + 1)*.5;
        cout<<c<<'\n';
    }

    return 0;
}