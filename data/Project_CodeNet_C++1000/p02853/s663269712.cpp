#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int x,y;
    int answer = 0;
    cin >> x >> y;

    answer += max((4-x)*100000,0);
    answer += max((4-y)*100000,0);
    if(x == 1 && y == 1)answer += 400000;

    cout << answer << endl;

    return 0;
}