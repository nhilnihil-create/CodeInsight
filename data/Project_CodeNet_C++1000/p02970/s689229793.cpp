#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,D;
    cin >> N >> D;
    int count=0;
    while(true){
        N-=2*D+1;
        count++;
        if(N<=0)break;
    }    
    cout << count << endl;
}