#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    string s, t = "";
    cin >> s;
    long ans = 0, left = 0, right = 0, value = 0;
    vector<pair<long, long>> l;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '>' && s[i+1] == '<'){
            right++;
            l.push_back(make_pair(left, right));
            left = right = 0;
        }else{
            if(s[i] == '>') right++;
            else left++;
        }
    }
    if(left != 0 || right != 0) l.push_back(make_pair(left,  right));
    for(auto i : l){
        //cout << i.first << " " << i.second << endl;
        long m = max(i.first, i.second), mm = min(i.first, i.second);
        ans += m*(m+1)/2;
        if(mm > 1) ans += mm*(mm-1)/2;
    }
    cout << ans << endl;
    return 0;
    // < > < > < > < > < > < > < > < > < > > >
    //0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 3 2 1 0
}