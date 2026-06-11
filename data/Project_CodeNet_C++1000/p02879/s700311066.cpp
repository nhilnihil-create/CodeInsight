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
    int A,B;
    cin >> A >> B;
    if(A>=10 || B>=10) cout << -1 << endl;
    else cout << A*B << endl;


    return 0;
}