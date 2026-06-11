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
int main(){
    int a,b;
    cin >> a >> b;
    for(int i=10;i<12501;i++){
        if(i*8/100==a){
            if(i/10==b){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}