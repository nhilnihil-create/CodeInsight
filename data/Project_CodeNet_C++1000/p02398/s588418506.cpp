#include<iostream>
using namespace std;
int main(int a,int b,int c){
    int i = 0;
    cin >> a >> b >> c;
    while(a <= b){
        if (c % a == 0) i++;
        a++;
    }
    cout << i << endl;
    return 0;
}
