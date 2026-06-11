#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int i=0;
    while(true){
        c -= b;
        if(c<=0){
            printf("Yes\n");
            return 0;
        }

         a -= d;
        if(a<=0){
            printf("No\n");
            return 0;
        }
    }

    return 0;
}
