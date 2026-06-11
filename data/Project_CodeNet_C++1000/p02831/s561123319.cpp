#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    int a,b;
    cin >> a >> b;
    if(a > b){
        ll x=a;
        while(x%b!=0){
            x+=a;
        }
        cout << x << endl;
    }else{
        ll x=b;
        while(x%a!=0){
            x+=b;
        }
        cout << x << endl;
    }
}