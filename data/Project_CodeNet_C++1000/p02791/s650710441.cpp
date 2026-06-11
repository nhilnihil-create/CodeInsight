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
    int p[n];
    for(int i=0;i<n;i++) cin >> p[i];
    
    int mi[n];
    mi[0]=p[0];
    for(int i=1;i<n;i++){
        if(mi[i-1]>=p[i]){
            mi[i]=p[i];
        }else{
            mi[i]=mi[i-1];
        }
    }

    /*for(int i=0;i<n;i++){
        cout << mi[i] << " "; 
    }
    cout << endl;*/

    int counter=0;
    for(int i=0;i<n;i++){
        if(p[i]<=mi[i]) counter++;
    }

    cout << counter << endl;
}