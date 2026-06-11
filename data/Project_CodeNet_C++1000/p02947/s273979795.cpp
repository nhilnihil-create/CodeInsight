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
    vector<string> s;
    for(int i=0;i<n;i++){
        string t;
        cin >> t;
        s.push_back(t);
    }

    
    for(int i=0;i<s.size();i++) sort(s.at(i).begin(),s.at(i).end());
    sort(s.begin(),s.end());
    //for(int i=0;i<n;i++) cout << s.at(i) << endl;
    
    ll ans=0,counter=1;
    for(int i=1;i<n;i++){
        if(s.at(i-1)==s.at(i)) {
            counter++;
        }else{
            ans+= counter*(counter-1)/2;
            counter=1;
        } 
    }
    ans+= counter*(counter-1)/2;

    cout << ans << endl;
}
