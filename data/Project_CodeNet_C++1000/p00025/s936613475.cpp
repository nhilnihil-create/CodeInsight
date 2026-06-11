#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

#define ll (long long)
#define REP(i,n) for(int i = 0;i<(int)n;i++)
#define FOR(i,a,b) for(int i = (a);i < (b);i++)
#define RFOR(i,a,b) for(int i = (a);i>(b);i--)


using namespace std;

int main (void){
    
    int a[500] = {0};
    int b[500] = {0};
    int i= 0,j = 0,k = 0,l = 0;
    int answer[1000][2] = {0};
    
    while(cin >> a[i++] >> a[i++] >> a[i++] >> a[i++])
    {
        cin >> b[j++] >> b[j++] >> b[j++] >> b[j++];
        
        FOR(m,i-4,i)
            if(a[m] == b[m])
                answer[l][0]++;
        FOR(m,i-4,i)
            FOR(k,i-4,i)
                if(a[m] == b[k] && m != k)
                    answer[l][1]++;
        l++;
    }
    REP(m,l)
    cout << answer[m][0] << " " << answer[m][1] << endl;
    return 0;
}