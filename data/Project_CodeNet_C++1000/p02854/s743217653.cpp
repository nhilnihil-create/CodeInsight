#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<cctype>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    cin >> N;
    ll A[N];
    ll i;
    ll sum=0;
    for(i=0;i<N;i++){
        cin >> A[i];
        sum+=A[i];
    }
    ll tmp=0,ans=sum;
    for(i=0;i<N;i++){
        tmp+=A[i];
        ans=min(ans,abs(sum-2*tmp));
    }
    cout << ans;
    return 0;
}