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
    int64_t x,k,d;
    cin >> x >> k >> d;
    x = abs(x);

    int64_t down=min(k,x/d);
    k -= down;
    x -= down*d;

    if(k%2==0){
        cout << x << endl;
    }else{
        cout << d-x << endl;
    }
}