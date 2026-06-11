#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007
#define rev(v) reverse(v.begin(), v.end());

bool comp(int a, int b){
    return (a<b);
}

int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    string flag;
    bool end = true;
    while(end){
        c-=b;
        if(c<=0){
            flag = "Yes";
            end = false;
            break;
        }
        a-=d;
        if(a<=0){
            flag = "No";
            end = false;
            break;
        }
    }
    cout << flag << endl;
    return 0;
}