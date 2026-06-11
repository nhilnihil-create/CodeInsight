#include<iostream>
using namespace std;
int main(){
    while(1){
        int N,n,suma=0,sumb=0,x,y;
        cin >> N;
        if(N==0)    break;
        n=N;
        while(n--){
            cin >> x >> y;
            if(x>y) suma=suma+x+y;
            else if(x == y) {
                suma+=x;
                sumb+=y;
            }
            else    sumb=sumb+x+y;
        }
        cout << suma << " " << sumb << "\n";
    }
    return 0;
}