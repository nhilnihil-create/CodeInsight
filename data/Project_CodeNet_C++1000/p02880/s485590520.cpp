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
    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++){
        if(N%i!=0) continue;
        int a=N/i;
        if(i<=9 && a<=9){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}