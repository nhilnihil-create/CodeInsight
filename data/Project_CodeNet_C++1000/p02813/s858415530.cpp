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
    vector<int> p,q;
    for(int i=0;i<n;i++){
        int v;
        cin >> v;
        p.push_back(v);
    }
    for(int i=0;i<n;i++){
        int v;
        cin >> v;
        q.push_back(v);
    }

    vector<int> r;
    for(int i=0;i<n;i++){
        r.push_back(i+1);
    }

    int a,b,counter=0;
    do{
        counter++;
        if(r==p) a=counter;
        if(r==q) b=counter;

    }while(next_permutation(r.begin(),r.end()));

    cout << abs(b-a) << endl;
}