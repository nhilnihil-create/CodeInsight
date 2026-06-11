#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

long long N;

int main(){
    cin >> N;
    
    long long x=1;
    int cnt = 1;
    while(x*26+1<=N){
        x=x*26+1;
        cnt++;
    }
    N-=x;
    string ans;
    for(int i=0; i<cnt; i++){
        ans+=char(N%26+int('a'));
        N/=26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}