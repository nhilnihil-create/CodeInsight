#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
typedef long long i64;

int main(){
    int n,p;
    while (true) {
        cin >> n >> p;
        if(n==0 && p==0) break;
        int currentp = p;
        vector<int> candidate;
        rep(i,n) candidate.push_back(0);
        int turn=0;
        while(true){
            if(currentp==0){
                currentp=candidate[turn];
                candidate[turn]=0;
            }else{
                candidate[turn]++;
                currentp--;
                if(currentp==0 && candidate[turn]==p) break;
            }
            turn=(turn+1)%n;
        }
        cout << turn << endl;
    }
  return 0;
}