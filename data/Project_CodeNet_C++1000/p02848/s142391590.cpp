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
    string s;
    cin >> n >> s;
    for(int i=0;i<s.size();i++){
        if(int(s.at(i))+n>90){
            s.at(i)=char(int(s.at(i))+n-26);
        }else{
            s.at(i)=char(int(s.at(i))+n);
        }
    }

    for(int i=0;i<s.size();i++) cout << s.at(i);
    cout << endl;
}