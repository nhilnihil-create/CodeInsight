#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<string, int> M;
    for(int i=0; i<n; i++){
        string s;
        cin >>  s;
        M[s]++;
    }
    int maxv = 0;
    for(auto& it : M){
        if((it.second)>maxv){
            maxv = it.second;
        }
    }
    for(auto it = M.begin(); it!=M.end(); it++){
        if(it->second == maxv){
            cout << it->first << endl;
        }
    }
    return 0;
}