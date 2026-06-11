#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> s;
    for(int i=0;i<n;i++){
        string ns;
        cin >> ns;
        s.push_back(ns);
    }

    sort(s.begin(),s.end());

    // for(int i=0;i<n;i++) cout << s.at(i) << endl;

    int counter=1;
    for(int i=1;i<n;i++){
        if(s.at(i-1)!=s.at(i)) counter++;
    }

    cout << counter << endl;
}