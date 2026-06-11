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
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    cin >> N;
    ll p,cnt=0,i;
    for(i=0;i<N;i++){
        cin >> p;
        if(p!=i+1)cnt++;
    }
    if(cnt<=2)cout << "YES";else cout<<"NO";
    return 0;
}
