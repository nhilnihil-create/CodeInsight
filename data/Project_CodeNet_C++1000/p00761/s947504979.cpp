#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cctype>
using namespace std;
const int L = 6;
const int N = 1000100;
#define REP(i, j) for(int i = 0; i < j; i++)
#define FOR(i, j, k) for(int i = j; i < k; i++)

string to_s(int n, int l){
    stringstream ss;
    ss <<n;
    string ret = ss.str();
    while(ret.length() < l) ret = "0" + ret;
    return ret;
}

int main(){
    int fir, l;
    while(cin >>fir >>l && (fir || l)){
        vector<int> v(N, -1);
        string now = to_s(fir, l);
        v[atoi(now.c_str())] = 0;
        for(int i = 1; ; i++){
            string tmp = now;
            sort(tmp.rbegin(), tmp.rend());
            string max = tmp;
            tmp = now;
            sort(tmp.begin(), tmp.end());
            string min = tmp;
            now = to_s(atoi(max.c_str()) - atoi(min.c_str()), l);
            if(v[atoi(now.c_str())] != -1){
                cout <<v[atoi(now.c_str())] <<" " <<atoi(now.c_str()) <<" " <<i - v[atoi(now.c_str())] <<endl;
                break;
            } else{
                v[atoi(now.c_str())] = i;
            }
        }
    }
    return 0;
}