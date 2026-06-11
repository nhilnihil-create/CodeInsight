#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int m,d;
    cin>>m>>d;
    int c=0;
    for (int i=1; i<=m; i++) {
        for (int j=10; j<=d; j++) {
            int l=j/10;
            int n=j%10;
            if (i==l*n && l>=2 && n>=2) c++;
        }
    }
    cout<<c<<endl;
    return 0;
}