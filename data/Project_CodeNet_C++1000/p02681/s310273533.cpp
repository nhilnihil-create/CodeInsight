#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    string s,t; cin>>s>>t;
    t.pop_back();
    if(s == t){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
