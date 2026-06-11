#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using ll=long long;
using namespace std;

int main(){
    int N;
    cin>>N;

    string s;
    map<string,int> m;
    int maxnum=0;
    for(int i=0;i<N;i++){
        cin>>s;
        m[s]++;
        if(m[s]>maxnum){
            maxnum=m[s];
        }

    }

    for(auto p:m){
        if(p.second==maxnum){
            cout<<p.first<<endl;
        }
    }
    
    return 0;
}