#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,k,n) for(int i=k;i<(int)(n);i++)

#define vi vector<int>
#define pb push_back

typedef long long ll;

bool SO[1000100];

void erast(int n){
    memset(SO,1,sizeof(SO));
    SO[1] = false;
    SO[0] = false;
    REP(i,2,sqrt(n)){
        if(SO[i]){
            REP(j,2,n){
                if(i*j>=1000000) break;
                SO[i*j] = false;
            }
        }
    }
}

int main(){
//    ifstream in("ain.txt");
//    cin.rdbuf(in.rdbuf());
    erast(1000001);
    int n;
    while(cin >> n,n){
        int cnt =0;

        REP(i,n+1,2*n+1){
            if(SO[i]) cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}
