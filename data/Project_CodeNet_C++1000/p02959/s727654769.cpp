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
    ll a[n+1];
    for(int i=0;i<n+1;i++) cin >> a[i];
    int b[n];
    for(int i=0;i<n;i++) cin >> b[i];

    ll sum=0;
    for(int i=0;i<n;i++){
        if(b[i]<=a[i]){
            sum+=b[i];
        }else{
            sum+=a[i];
            b[i]-=a[i];
            if(a[i+1]>=b[i]){
                sum+=b[i];
                a[i+1]-=b[i];
            }else{
                sum+=a[i+1];
                a[i+1]=0;
            }
        }
    }

    cout << sum << endl;    
}