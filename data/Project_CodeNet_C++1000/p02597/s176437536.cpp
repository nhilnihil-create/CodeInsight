#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int redcount=0,whitecount=0;
    int leftcount=0,rightcount=0;
    REP(i,n){
        if(s[i]=='W')whitecount++;
        else redcount++;
    }
    REP(i,redcount){
        if(s[i]=='R')leftcount++;
    }
    REP(i,whitecount){
        if(s[s.length()-i-1]=='W'){
            rightcount++;
        }
    }
    cout << min(whitecount-rightcount,redcount-leftcount) << endl;

    return 0;
}