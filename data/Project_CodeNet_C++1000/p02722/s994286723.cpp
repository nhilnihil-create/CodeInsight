#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
set<long long > ss;
long long n;
void solve(long long i){
    //cout << i << endl;
    long long tmp =n;
    while(tmp!=1){
        if((tmp-1)%i==0){
        ss.insert(i);
            return ;
        }
        if(tmp%i)
            return;
        tmp=tmp/i;
    }
    ss.insert(i);
}
int main()
{
    cin >> n;
    for(long long i=1;i*i<=n;i++){
        if((n-1)%i==0)
        {
            ss.insert(i);
            ss.insert((n-1)/i);
        }
        if(n%i==0){
            solve(i);
            solve(n/i);
        }
    }

    cout << ss.size()-1 << endl;
    return 0;
}
