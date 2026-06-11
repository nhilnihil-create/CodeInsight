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
    int n,x;
    cin >> n >> x;
    int l[n];
    for(int i=0;i<n;i++) cin >> l[i];

    int sum=0;
    int counter=1;
    for(int i=0;i<n;i++){
        sum += l[i];
        if(sum<=x){
            counter++;
        }
    }

    cout << counter << endl;
}