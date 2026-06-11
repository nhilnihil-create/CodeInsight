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
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    int counter=1;
    for(int i=0;i<n;i++){
        if(counter==a[i]) counter++;
    }

    if(counter==1){
        cout << -1 << endl;
    }else{
        cout << n-counter+1 << endl;
    }
}