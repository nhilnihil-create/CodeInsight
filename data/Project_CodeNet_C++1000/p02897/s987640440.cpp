#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)

#include <string>
#include <vector>
#include <algorithm>
int main(){
    int n; cin >> n;
    if(n%2==0){
        cout << 0.5 << endl;
    } else {
        printf("%f\n",(double)(n/2+1)/n);
    }
}