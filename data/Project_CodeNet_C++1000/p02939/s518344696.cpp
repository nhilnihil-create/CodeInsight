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
    string S;
    cin >> S;
    ll ans=0;
    ll i;
    for(i=0;i<S.size();i++){
        if(i!=S.size()-1&&S[i]==S[i+1]){
           if(i!=S.size()-2)ans++;
           i+=2;
        }
        ans++;
    }
    cout << ans;
    return 0;
}