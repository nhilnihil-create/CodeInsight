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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int turn=1;
    while(a>0 && c>0){
        if(turn){
            c -= b;
            turn =0;
        }else{
            a -= d;
            turn =1;
        }
    }

    if(turn){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}