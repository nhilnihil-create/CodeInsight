#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main(){
    int a, b, c, k;
    cin >> a >> b >> c >>k;
    if(k<=a){
        cout << k << endl;
        return 0;
    }
    if(k<=a+b){
        cout << a << endl;
        return 0;
    }
    if(k<=a+b+c){
        int d = k-a-b;
        cout << a-d << endl;
        return 0;
    }
}