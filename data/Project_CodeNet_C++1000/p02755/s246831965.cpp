#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
using namespace std;

int main(void){
    // Your code here!
    double A,B;
    cin >> A >> B;

    for(double i = 1; i < 1250; i++){
        if(floor(i * 0.08) == A && floor(i * 0.1) == B){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
