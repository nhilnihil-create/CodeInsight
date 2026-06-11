#include <bits/stdc++.h>
using namespace std;
int main(void){
    int m,d;
    cin>>m>>d;
    int count=0;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=d;j++) {
            if (j/10>=2&&j%10>=2) {
                if ((j/10)*(j%10)==i) {
                    //cout<<i<<" "<<j<<endl;
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
}