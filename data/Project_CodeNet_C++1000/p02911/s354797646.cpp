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
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> score(n,0);
    vector<int> border(n,k);
    vector<string> mem(n,"No");

    for(int i=0;i<q;i++){
        int a;
        cin >> a;
        a--;
        score.at(a)++;
    }

    //for(int i=0;i<n;i++) cout << score.at(i) << endl;

    for(int i=0;i<n;i++){
        border.at(i)=k-q+score.at(i);
        if(border.at(i)>0) mem.at(i)="Yes";
    }

    for(int i=0;i<n;i++) cout << mem.at(i) << endl;
}