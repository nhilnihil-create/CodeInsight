#include<iostream>
#include<vector>
#include<algorithm>

#define REP(i,n) for(int i=0;i<(n);i++)

using namespace std;

// return sum of seq[a,b]
int sum_seq(int a, int b){
    int res = 0;
    for(int k=a; k<=b;k++) res+=k;
    return res;
}

int solve(int n){
    int cnt = 0;
    for(int s=1;s<n;s++){
        for(int e=1;e<n;e++){
            if(e <= s) continue;
            if(sum_seq(s,e) == n) cnt++;
        }
    }
    return cnt;
}

int main(){
    int n;
    while(cin >> n){
        if(n==0) break;
        cout << solve(n) << endl;
    }
    return 0;
}