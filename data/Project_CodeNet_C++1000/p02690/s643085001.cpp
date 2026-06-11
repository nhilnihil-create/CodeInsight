#include <iostream>
using namespace std;

#include <string>
#include <vector>
int main(){
    int x; cin >> x;
    int a,b;
    for(a=-118; a<=119; a++){
        int a5 = a*a*a*a*a;
        for(b=a-1; b>=-119; b--){
            if(x%(a-b))continue;
            if(x==a5-b*b*b*b*b){
                printf("%d %d\n",a,b);
                return 0;
            }
        }
    }
}