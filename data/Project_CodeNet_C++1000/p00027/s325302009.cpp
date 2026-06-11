#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

string date[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int main(){

    int year = 2004,month,day;

    while(cin >> month >> day){
    
        if(month == 0){
            return 0;
        }

        if(month == 1 || month==2){
            year--;
            month += 12;
        }
    
        int tmp = (year + year/4 - year/100 + year/400 + (13*month+8)/5 + day)%7;
    
        cout << date[tmp] << endl;
    }
    
    return 0;

}
