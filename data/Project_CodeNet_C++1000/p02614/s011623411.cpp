#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1000000007
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              10
char arr[sz][sz];

int solve(int n, int m, int k){

    int tot=0;
    for(int maskR=0; maskR<(1<<n); maskR++){
        for(int maskC=0; maskC<(1<<m); maskC++){
            int black=0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(((maskR>>i)&1)==0 && ((maskC>>j)&1)==0 && arr[i][j]=='#')black++;
                }
            }
            tot+=(black==k);
        }

    }
    return tot;

}

int main(){
    Fast;///using Fast I/O
    int n,m,k;

    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    cout<<solve(n, m, k)<<endl;
    return 0;
}

