#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;

    float x = (float)n/(float)1.08;
    int y = ceil(x)*1.08;
    if(y==n)
        cout << ceil(x);
    else
        cout << ":(";
    return 0;
}