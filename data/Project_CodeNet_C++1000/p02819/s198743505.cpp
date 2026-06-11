#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
#include <numeric>
 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
string S,T;
vector<ll> so;


ll N,K,M;

int main() {
    cin >> N;
    ll i = 2;
    while(true){
        bool found = false;
        for(int j=0;j<so.size();j++){
            if(i%so[j]==0){
                found = true;
                break;
            }
        }
        if(!found){
            so.push_back(i);
            if(i>=N){
                cout << i << endl;
                return 0;
            }
        }
        i++;
    }
    
}
