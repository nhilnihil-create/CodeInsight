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
    int h1,h2,m1,m2,k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int diff;
    if(h1 < h2){
        int a = h1*60+m1;
        int b = h2*60+m2;
        diff = b-a;
    }else if(h1 > h2){
       int a = h1*60+m1;
        int b = h2*60+m2;
        diff = b-a;
    }
    else{
        if(m1 < m2){
            int a = h1*60+m1;
        int b = h2*60+m2;
        diff = b-a;
        }else if(m1 > m2){
            int a = h1*60+m1;
        int b = h2*60+m2;
        diff = b-a;
        }
        else{
            diff = 0;
        }
    }
    cout << diff - k << endl;
    return 0;
}