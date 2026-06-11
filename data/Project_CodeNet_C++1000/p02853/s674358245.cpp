#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a,b;
    cin >> a >> b;
    int sum = 0;
    if(a+b == 2)sum += 400000;
    if(a <= 3)sum += (4-a)*100000;
    if(b <= 3)sum += (4-b)*100000;
    cout << sum << endl;
}