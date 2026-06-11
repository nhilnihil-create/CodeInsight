#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    if (n<m) {
        for(int i=0;i<m;i++)printf("%d",n);
    } else {
        for(int i=0;i<n;i++)printf("%d",m);
    }
    puts("");
}