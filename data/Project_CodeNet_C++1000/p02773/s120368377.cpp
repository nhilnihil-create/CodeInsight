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
using intl = int64_t;
using graph = vector<vector<int> >;
int main(){
    int n;
    cin >> n;
    vector<string> s;
    for(int i=0;i<n;i++){
        string l;
        cin >> l;
        s.push_back(l);
    }
    //for(int i=0;i<n;i++) cout << s.at(i) << endl;

    sort(s.begin(),s.end());

    // for(int i=0;i<n;i++) cout << s.at(i) << endl;

    map<string,int> vote;
    vote[s.at(0)]=1;
    for(int i=1;i<n;i++){
        if(s.at(i-1)==s.at(i)){
            vote.at(s.at(i-1))++;
        }else{
            vote[s.at(i)]=1;
        }
    }

    int counter=0;
    for(auto p: vote){
        auto key=p.first;
        auto value=p.second;

        counter= max(vote.at(key),counter);
    } 

    for(auto p: vote){
        auto key=p.first;
        auto value=p.second;

        if(vote.at(key)==counter) 
            cout << key << endl;
    } 
}