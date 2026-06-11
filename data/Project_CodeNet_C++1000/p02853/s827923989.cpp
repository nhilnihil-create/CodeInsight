#include <iostream>
using namespace std;
int main(void){
    int x, y;
    cin >> x >> y;
    int prize[206]={0,300000,200000,100000};
    int sum = 0;
    if(x==1&&y==1) sum += 1000000;
    else sum += prize[x]+prize[y];
    cout << sum << endl;
}
