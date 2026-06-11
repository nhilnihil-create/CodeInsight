#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <map>
#include <queue>
#include <tuple>
#include <math.h>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> P;


int main(){
    int A,B,K;
    cin >> K >> A >> B;
    string ans="NG";
    for(int i=A; i<=B; i++){
        if(i%K==0) ans="OK";
    }
    cout << ans << endl;

    return 0;
}