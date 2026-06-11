#include <iostream>
using namespace std;
int main(){
    int n, cnt=0;
    scanf("%d",&n);
    for(int i=1; i<=n/2+1; i++){
        if( i != n-i && i < n-i ) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}