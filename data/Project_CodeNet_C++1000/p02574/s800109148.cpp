#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
#define MAX 1001000
//#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    LL n;
    cin >> n;
    vector<LL> a(n);
    LL max_num=0;
    for(LL i=0; i<n; i++){
        cin >> a[i];
        max_num=max(max_num, a[i]);
    }

    vector<LL> num_sum(max_num+1, 0);

    for(LL i=0; i<n; i++){
        for(LL j=2; j*j<=a[i]; j++){
            if(a[i]%j==0){
                while(a[i]%j==0){
                    a[i]/=j;
                }
                num_sum[j]++;
            }
        }
        if(a[i]!=1){
            num_sum[a[i]]++;
        }
    }

    LL max_ans=0;
    for(LL i=0; i<num_sum.size(); i++){
        max_ans=max(max_ans, num_sum[i]);
    }

    if(max_ans==1 || max_ans==0){
        cout << "pairwise coprime" << endl;
    }else if(max_ans<n){
        cout << "setwise coprime" << endl;
    }else{
        cout << "not coprime" << endl;
    }

    return 0;
}
