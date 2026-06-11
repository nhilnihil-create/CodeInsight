#include <iostream>
using namespace std;
int main(void){
    char N[1000000];
    int a=0, b=11;
    int a1,b1;
    cin >> N;
    for(int i=0;N[i];i++){
        a1 = min(a+N[i]-'0',b+N[i]-'0');
        b1 = min(a+11-N[i]+'0',b+9-N[i]+'0');
        a = a1;
        b = b1;
    }
    cout << min(a,b);
}