#include <bits/stdc++.h>
using namespace std;
int main(void){
 
    int N,D,c=0;
    cin >> N >> D;
    
    int i=1;
    while(1){
        c++;
        if((2*D+1)*i >= N) break;
        i++;
    }
    
    cout << c <<endl;
}