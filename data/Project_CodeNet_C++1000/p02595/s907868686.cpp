#include <iostream>
using namespace std;
int main(void){
    long long int n,d,x,y,cnt=0;
    cin >> n >> d;
    d *= d;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        if(d>=x*x+y*y) cnt++;
    }
    cout << cnt;
}