#include<iostream>
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
    int x,y;
    cin >> x >> y;
    int a,b;
    a = y-2*x;
    b = 4*x-y;
    if(a>=0 && b>=0 && a%2==0 && b%2==0){
        cout << "Yes" <<endl;
    }else{
        cout << "No" << endl;
    }
}