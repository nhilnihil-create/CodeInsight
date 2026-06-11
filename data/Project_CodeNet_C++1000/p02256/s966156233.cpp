#include <iostream>
using namespace std;
int main(void){
    int a,b;
    int c;
    cin >> a;
    cin >> b;
    if(a>b)
        c=a-b;
    else
        c=b-a;
    if(a==b)
        cout << a << "\n";
    for(int i=c;i>0;i--){
        if(a%i == 0 && b%i==0){
            cout << i << "\n";
            break;
        }
    }
}