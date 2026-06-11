#include<bits/stdc++.h>
using namespace std;
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
int main(void)
{
    int n, cnt=0;
    cin >> n;
    REP(i,1,n+1){
        string s = to_string(i);
        if(s.size()%2) cnt++;
    }
    cout << cnt << endl;
    return 0;
}