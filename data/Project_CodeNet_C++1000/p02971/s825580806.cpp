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
    vector<pair<int,int> > a;
    for(int i=0;i<n;i++){
        int b;
        cin >> b;
        a.push_back(make_pair(b,i));
    } 

    /*for(int i=0;i<n;i++){
        cout << a[0].second << ':' << a[i].first << endl;
    }*/

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    for(int i=0;i<n;i++){
        if(a[0].second!=i){
            cout << a[0].first << endl;
        }else{
            cout << a[1].first << endl;
        }
    }
}