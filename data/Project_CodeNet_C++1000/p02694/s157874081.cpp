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
    int64_t x;
    cin >> x;
    int64_t counter=0,prop=100;
    while(prop<x){
        prop += prop/100;
        counter++;
    }
    cout << counter << endl;
}