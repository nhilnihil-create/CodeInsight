#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
    char c[3];
    int a = 0,maxa;
    cin >> c;
    maxa = a;
    for(int i=0;i<3;i++){
        if(c[i] == 'R'){
            a++;
            maxa = max(maxa,a);
        }else{
            a = 0;
        }
    }
    cout << maxa << endl;
    return 0;
}