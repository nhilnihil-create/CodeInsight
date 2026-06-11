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
    string s;
    cin >> s;

    int counter=n;
    for(int i=1;i<n;i++){
        if(s.at(i-1)==s.at(i)) counter--;
    }

    cout << counter << endl;
}