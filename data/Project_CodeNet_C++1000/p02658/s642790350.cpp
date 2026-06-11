#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int64_t a[n];
    int i,zero=0;
    for (i=0;i<n;i++){
        cin >> a[i];
        if(a[i]==0) zero++;
    }
    if(zero>0){
        cout << 0 << endl;
        return 0;
    }
    int64_t mul=1;
    for(i=0;i<n;i++){
        if(a[i]<= (1000000000000000000/mul)){
            mul *= a[i];
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << mul << endl;
}