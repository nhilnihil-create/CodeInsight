#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int main(){
    ll T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    ll term1=(A1-B1)*T1;
    ll term2=(A2-B2)*T2;
    if(term1<0){
        term1*=-1;
        term2*=-1;
    }

    if(term1+term2==0){
        cout << "infinity" << endl;
    }else if(term1+term2>0){
        cout << 0 << endl;
    }else{
        ll ans=2*(term2/(term1+term2)-1)+1;
        if(term2%(term1+term2)==0){
            ans--;
        }
        cout << ans << endl;
    }
}