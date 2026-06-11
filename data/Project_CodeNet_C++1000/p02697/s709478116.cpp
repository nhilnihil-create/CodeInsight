#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MAX 1001000
#define MOD 1000000007
#define endl "\n"
lli arr[MAX];
lli N;
lli M;
lli Q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    t = 1;
    while(t--){
            lli N,M;
            cin>>N>>M;
            lli a = N/2;
            lli b = N/2+1;
            if(N%2 == 0){
                vector <bool> visited(N+5, 0);
                lli aeven = 1;
                lli beven = N/2;
                lli aodd = N;
                lli bodd = N/2 + 2;
                while(beven > aeven & M > 0){
                    cout<<aeven<<" "<<beven<<endl;
                    aeven++;
                    beven--;
                    M--;
                    }
                while(aodd > bodd & M > 0){
                    cout<<aodd<<" "<<bodd<<endl;
                    aodd--;
                    bodd++;
                    M--;
                }
            }
            else{
                for(lli i = 0; i<M; i++){
                    cout<<a<<" "<<b<<endl;
                    a--;
                    b++;
                }
            }
        }
    }