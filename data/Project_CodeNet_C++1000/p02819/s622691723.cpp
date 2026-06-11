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
    int x;
    cin >> x;
    int find=1;
    while(find){
        int check=1;
        for(int i=2;i<x;i++){
            if(x%i==0) {
                check=0;
                break;
            }
        }
        if(check) {
            cout << x << endl;
            break;
        }else{
            x++;
        }
    }
}